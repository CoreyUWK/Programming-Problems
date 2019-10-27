/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <queue>
#include<bits/stdc++.h> 
#include <sstream>
#include <string>
using namespace std;

string compress (string s)
{
    string compStr;
    int charCount = 0;
    
    if (s.empty())
    {
        return s;
    }
    if (s.size() == 1)
    {
        return s;
    }
    
    compStr.reserve(s.size());
    
    for (char c : s)
    {
        if (compStr.empty())
        {
            compStr += c;
            charCount = 0;
        }
        else if (compStr.back() != c)
        {
            compStr += to_string(charCount);
            compStr += c;
            charCount = 0;
        }
        
        ++charCount;
    }
    compStr += to_string(charCount);
    return (compStr.size() <= s.size()) ? compStr : s;
}

int main()
{
    cout << compress("abc") << endl;
    cout << compress("aabc") << endl;
    cout << compress("aabbc") << endl;
    cout << compress("aabbbc") << endl;

    return 0;
}
