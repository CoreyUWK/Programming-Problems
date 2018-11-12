/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;


string reverse(string s) {
    std::stack<string> stack;
    string out = "";
    
    int start = 0;
    for (int i = start; i < s.size(); ++i) {
        if (s[i] == ' ' || i >= s.size() - 1) {
            stack.push(s.substr(start, i - start + ((i >= s.size() - 1) ? 1 : 0) ));
            start = i + 1;
        }
    }
    
    while (!stack.empty()) {
        out += stack.top() + " ";
        stack.pop();
    }
    
    return out;
}


int main()
{
    cout << reverse("My name is Corey");
    return 0;
}
