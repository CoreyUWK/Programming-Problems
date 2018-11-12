/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

string compress(string s)
{
    string out = "";
    
    if (0 == s.length())
        return s;
        
    char prev = s[0];
    int count = 1;
    out += prev;
    for (int i = 1; i < s.length(); prev = s[i], ++i)
    {
        // compress
        if (s[i] == prev)
            ++count;
        else
        {
            out += std::to_string(count);
            out += s[i];
            count = 1;
        }
    }
    
    out += std::to_string(count);
    return out;
}

string compress(string s) {
    if (s.length() == 0) return s;
    string out = "";
    
    int count = 1;
    char prev = s[0];
    for (int i = 1; i < s.length() + 1; prev = s[i], ++i) {
        if (i < s.length() && s[i] == prev) {
            ++count;
        }
        else {
            out += prev + std::to_string(count);
            count = 1;
        }
    }
    
    return out;
}

int main()
{
    cout << compress("aaabbbcccde");

    return 0;
}
