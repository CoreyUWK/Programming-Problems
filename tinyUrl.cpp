/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//https://www.geeksforgeeks.org/how-to-design-a-tiny-url-or-url-shortener/

/* https://www.youtube.com/watch?v=fMZMm_0ZhK4
 https://www.infoworld.com/article/3063161/nosql/why-redis-beats-memcached-for-caching.html
https://zookeeper.apache.org/doc/r3.3.3/index.html (Zookeeper)
https://en.wikipedia.org/wiki/Content_delivery_network (CDN)

Restful api
Load balancer
zookeeper
nosql
CDN
MD5
memcached or redis

user request -> RESTFUL API -> load balancer -> worker threads -> cache layer or persistence layer

A-Z = 26
a-z = 26
0-9 = 10
Total = 62 => 62

Choose length of tinyUrl based on service rate and more than number of websites
-> if 1000 requests/sec -> 62^7 = 3.5 trill therefore or 43bits -> 110 years 

-Database table schema (tinyUrl<key>, longUrl)

possible solutions for generating tinyUrl
1) generate random tiny url and check database if already exists
	-method of updating database with 
	1) get(tinyUrl), if does not exist, put(tinyUrl)
		- problems with this is in multiple requests at same time, race condition
	2) put if absent(tinyUrl) 
		- problem is requires database support, most support is on relational db but
		relational db do not scale well for multiple servers like NoSql based and might have
		service costs
	3) put(tinyUrl), get(tinyUrl) and check if match, if not regenerate tinyUrl and put again (loop)
2) pick first 43 bits of md5
- md5 generates 128bit hash
- possible collisions as were taking 43 or the 128bits so could have duplicates
- therefore, take 43bits, convert to tinyUrl, check if database contains
- advantage of saving space from random URL as same URL will generate same md5 hash
3) counter (single host, all host, range based)
- single host responsible for maintaining counter (zookeeper), passes to worker host
	- problem single point of failure and signle resource might not be able to handle load
- every host maintains counter instead 
	- 6bits (0-63) + 32bit(timestamp) + 5bits(random/increamental) = 43bits
	- 
- range based  on zookeeper, worker threads/hosts come to zookeeper and request an unused range and claims a range
	- W1 1->1mill
	- W2 1mill-2mill
	- WN 999mill-1bill
*/

#include <iostream>
#include <algorithm>    // std::reverse
#include <vector>
using namespace std;

/* Solutions:
 1) Hashmap to convert URL to short string
	- issue need a hash function to get short string, maybe position in hashmap (index)
    - may be collisions, hence not bijective
 2) Better solution: use increamenting integer id stored in database and convert
	integer id to character string, which is a base convserion problem. 
	- to get original url need to get url id in database */

// Map to store 62 possible characters
const string map = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

/* Function to generate a short URL from integer ID. 
Convert from base 10 to base 62 */
string idToShortUrl(long unsigned int id) {
    string shortUrl;

    // Convert given integer id to a base 62 number 
    do {
        // use above map to store actual character in short URL
        shortUrl.push_back(map[id % map.size()]);
        id /= map.size();  
    } while (id > 0);
    
    return shortUrl;
}
 
/* Function to get integer ID back from a short URL.
Base 62 to base 10 */ 
long unsigned int shortUrlToId(string shortUrl) {
    long unsigned int id = 0;

    // A simple base conversion logic 
    for (int i=shortUrl.length() - 1; i >= 0 ; --i) 
    { 
        if ('a' <= shortUrl[i] && shortUrl[i] <= 'z') {
            id = (id * map.size()) + shortUrl[i] - 'a';
        }
        if ('A' <= shortUrl[i] && shortUrl[i] <= 'Z') {
            id = (id * map.size()) + shortUrl[i] - 'A' + 26; 
        }   
        if ('0' <= shortUrl[i] && shortUrl[i] <= '9') { 
            id = (id * map.size()) + shortUrl[i] - '0' + 52;
        }
    }
    
    return id; 
}


long unsigned int shortUrlToId2(string shortUrl) {
    long unsigned int id = 0;
     for (int i = shortUrl.size() - 1; i >= 0; --i) {
        if ('a' <= shortUrl[i] && shortUrl[i] <= 'z') {
           id += ( (shortUrl[i] - 'a') * (pow(62, i)) );
        }
        else if ('A' <= shortUrl[i] && shortUrl[i] <= 'Z') {
            id += ( ((shortUrl[i] - 'A') + 26) * (pow(62, i)) );
        }
        else if ('0' <= shortUrl[i] && shortUrl[i] <= '9') {
            id += ( ((shortUrl[i] - '0') + 52) *  (pow(62, i)) );
        }
    }
    return id;
}

int main()
{
    int n = 12345; 
    string shorturl = idToShortUrl(n); 
    cout << "Generated short url is " << shorturl << endl; 
    cout << "Id from url is " << shortUrlToId(shorturl); 
    return 0;
}
