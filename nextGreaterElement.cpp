/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

std::vector<int> nextGreateStack(const std::vector<int> &arr) {
    std::vector<int> ng;
    std::stack<int> stack;
    
    stack.push(0);
    unordered_map<int, int> map;
    
    for (int i = 0; i < arr.size(); ++i)
    {
        // Push onto stack as long as array item less than top of stack (not at a max yet)
        if (arr[i] < arr[stack.top()]) {
            stack.push(i);
            continue;
        }
        
        // pop off stack if at a current max for top of stack and mark in map
        while (!stack.empty() && arr[stack.top()] < arr[i]) {
            map[stack.top()] = i;
            stack.pop();
        }
        
        // push current max i onto stack
        stack.push(i);
    }
    
    // Mark remaining on stack to not have a max 
    while (!stack.empty()) {
        map[stack.top()] = -1;
        stack.pop();
    }
    
    // Move over map to list in order of index
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " -> " << ((map[i] == -1) ? -1 : arr[map[i]]) << endl;
        ng.push_back(map[i]);
    }
    
    return ng;
}

int main()
{
    std::vector<int> arr = {4, 2, 1, 3, 2, 7};
    std::vector<int> ng = nextGreateStack(arr);
    for (int i : ng) {
        cout << i << ", ";
    }
    cout << endl;

    return 0;
}
