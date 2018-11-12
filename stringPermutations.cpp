/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

void permute(string s, int start) {
    //cout << s << " " << start << endl;

    if (start >= s.size()) {
        cout << s << endl;
        return;
    }
    
    for (int i = start; i <= s.size() - 1; ++i) {
        swap(s[start], s[i]);
        permute(s, start + 1);
        swap(s[start], s[i]);
    }
}

int main()
{
    permute("ABC", 0);

    return 0;
}
