/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <stack>
using namespace std;

class MaxStack
{
    typedef struct Item 
    {
        int value;
        struct Item *maxItem;
    } Item;
    
    stack<Item> maxStack;
    
    public:
    
    void push(int value)
    {
        Item newItem;
        newItem.value = value;
        newItem.maxItem = NULL;

        if (!maxStack.empty())
        {
            if (maxStack.top().maxItem == NULL && maxStack.top().value > newItem.value)
            {
                newItem.maxItem = &maxStack.top();
            }
            else if (maxStack.top().maxItem != NULL && 
                maxStack.top().maxItem->value > newItem.value)
            {
                newItem.maxItem = maxStack.top().maxItem;
            }
        }

        maxStack.push(newItem);
    }
    
    int top()
    {
        if (maxStack.empty()) return -1;
        return maxStack.top().value;
    }
    
    void pop()
    {
        maxStack.pop();
    }
    
    int max()
    {
        if (maxStack.empty()) return -1;
        return (maxStack.top().maxItem == NULL) ? top() : maxStack.top().maxItem->value;
    }
    
    bool empty()
    {
        return maxStack.empty();
    }
};

int main()
{
    MaxStack maxStack;
    
    for (int i = 1; i < 10; ++i)
    {
        maxStack.push(i);
        cout << maxStack.max() << ", ";
    }
    cout << endl;

    for (int i = 50; i >= 30; i -= 5)
    {
        maxStack.push(i);
        cout << maxStack.max() << ", ";
    }
    cout << endl;
    
    while (!maxStack.empty())
    {
        cout << maxStack.top() << ", ";
        maxStack.pop();
    }
    return 0;
}
