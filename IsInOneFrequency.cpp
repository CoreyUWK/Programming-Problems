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
#include <set>
using namespace std;


bool inOneCheck(int map[], size_t size) {
    set<int> uniqueList;
    for (int i = 0; i < size; ++i) {
        // Add to list all instances of characters in string
        // set will only contain unique values, so size should be 1 if 
        // all characters occur with the same frequency
        if (map[i] > 0) uniqueList.insert(map[i]);
    }
    
    return (uniqueList.size() == 1 || uniqueList.size() == 0);
}


bool isInOne(string s) {
    const int alphaSize = 26;
    int map[alphaSize] = {0};
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    
    for (char c : s) {
        ++map[c - 'a'];
    }
    
    bool inOne = inOneCheck(map, alphaSize);
    for (int i = 0; !inOne && i < alphaSize; ++i) {
        // If not all characters in string contain the same frequency go 
        // through all frequncies and subtract 1, then check if frequencies are 
        // all the same 
        if (map[i] > 0) {
            --map[i];
            inOne = inOneCheck(map, alphaSize);
            ++map[i];
        }
    }
}


int main()
{
    string str = "wwlleomepmp";
    
    bool inOne = isInOne(str);
    cout << (inOne ? "YES" : "NO") << endl;
    
    return 0;
}
