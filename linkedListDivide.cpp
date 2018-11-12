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

using namespace std;

struct Node {
    int value;
    struct Node * next;
};

struct Node * divide(struct Node *list)
{
    if (NULL == list) return NULL;
    struct Node * follower = list;
    struct Node * runner = list->next;
    
    // Find end of list and use follower to track middle
    while (NULL != runner)
    {
        runner = runner->next;
        if (NULL == runner) break;
        runner = runner->next;
        follower = follower->next;
    }
    
    // Remove next link from follower
    // Return follower.next
    struct Node *tmp = follower->next;
    follower->next = NULL;
    return tmp;
}

int main()
{
    struct Node * node = (struct Node *)malloc(sizeof(struct Node));
    struct Node * tmpPtr = node;

    int size = 11;
    for (int i = 0; i < size; ++i)
    {
        tmpPtr->value = i;
        if (i < (size - 1))
        {
            tmpPtr->next = (struct Node *)malloc(sizeof(struct Node));
            tmpPtr = tmpPtr->next;
        }
        else
            tmpPtr->next = NULL;
    }
    
    struct Node * out = divide(node);
    tmpPtr = node;
    cout << "First: " << endl;
    while (tmpPtr != NULL)
    {
        cout << tmpPtr->value << std::endl;
        tmpPtr = tmpPtr->next;
    }
    cout << "Second: " << endl;
    while (out != NULL)
    {
        cout << out->value << std::endl;
        out = out->next;
    }
    
    return 0;
}
