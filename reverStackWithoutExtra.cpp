/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <vector>  
#include <queue>
#include <stack>
using namespace std;


void insertToBottom(std::stack<int> &stack, int entry) {
    if (stack.empty()) {
        stack.push(entry);
        return;
    }
    
    int tmp = stack.top();
    stack.pop();
    insertToBottom(stack, entry);
    stack.push(tmp);
}


void reverseStack(std::stack<int> &stack)
{
    if (stack.empty()) return;
    
    int tmp = stack.top();
    stack.pop();
    reverseStack(stack);
    insertToBottom(stack, tmp);
}


void PrintStack(std::stack<int> &stack)
{
    if (stack.empty()) return;
    int tmp = stack.top();
    cout << tmp << " ";
    stack.pop();
    PrintStack(stack);
    stack.push(tmp);
}


int main()
{
    std::stack<int> stack;
    for (auto item : {1,2,3,4,5}) {
        stack.push(item);
    }
   
    cout << "Before:" << endl;
    PrintStack(stack);
    cout << endl;
    
    reverseStack(stack);
    
    cout << "After:" << endl;
    PrintStack(stack);
    cout << endl;

    return 0;
}
