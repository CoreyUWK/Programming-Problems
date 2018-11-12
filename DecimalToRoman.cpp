/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

static const std::vector<std::pair<string, int>> romanValue = { 
        {"M",  1000},
        {"CM", 900},
        {"D",  500}, 
        {"CD", 400},
        {"C",  100},
        {"XC", 90},
        {"L",  50},
        {"XL", 40},
        {"X",  10},
        {"IX", 9},
        {"V",  5},
        {"IV", 4},
        {"I",  1}
    };

string numToRoman(int num) {
    string roman = "";
    int i = 0;
    
    if (num < romanValue[romanValue.size() - 1].second) throw "Invalid num arg";
    
    while (num > 0) {
        // Find roman piece
        for (i = 0; i < romanValue.size(); ++i) {
            if (romanValue[i].second <= num) break;
        }
        
        roman += romanValue[i].first;
        num -= romanValue[i].second;
    }
    
    return roman;
}

int main()
{
    for (int i = 1; i < 500; ++i) {
        cout<< numToRoman(i)<< endl;
    }
   
    return 0;
}
