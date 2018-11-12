/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

bool isAnagram(string s1, string s2) {
    if (s1.length() != s2.length()) return false;
    
    std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    std::transform(s2.begin(), s2.end(), s2.begin(), ::tolower);

    // Create hashmap
    int letterMapSize = 1 << 8; // Num Characters
    int letterMap[letterMapSize] = {0};
    for (const char &c : s1) {
        ++letterMap[(int)c];
    }
    for (const char &c : s2) {
        --letterMap[(int)c];
    }
    
    for (int i = 0; i < letterMapSize; ++i) {
        if (letterMap[i] != 0) return false;
    }
    
    return true;
}

int main()
{
   cout << "Is anagram " << isAnagram("Hello", "elolH");

    return 0;
}

/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
#include <limits>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool isAnagram(string s1, string s2) {
    if (s1.length() != s2.length()) return false;
    
    unordered_map<char, int> map;
    
    std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    std::transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    
    for (char c : s1) {
        if (map.find(c) == map.end()) {
            map.insert({c, 1});
        }
        else {
            ++map[c];
        }
    }
    
    for (char c : s2) {
        if (map.find(c) == map.end()) return false;
        --map[c];
        if (map[c] <= 0) map.erase(c);
    }
    
    return true;
}

int main()
{
    cout << isAnagram("Hello", "elHoo");
    return 0;
}

