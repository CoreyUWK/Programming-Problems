/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <array>
#include <stack>
using namespace std;

typedef struct Node Node;
struct Node {
    int val;
    Node * next;
};

bool palindrome (Node *list)
{
    Node *curr = list;
    Node *runner = list;
    std::stack<int> stack;

    // Find Mid of list
    while (runner != NULL && runner->next != NULL)
    {
        stack.push(curr->val);
        curr = curr->next;
        runner = runner->next->next;
    }
    if (runner != NULL) curr = curr->next;
    
    // Check the two halves of list for same
    while (curr != NULL)
    {
        int val = stack.top();
        stack.pop();
        
        if (curr->val != val) return false;
        curr = curr->next;
    }
    return true;
}

int main()
{
    return 0;
}
