/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class MaxStack {
    
    class Node {
        Node *next;
        Node *max;
        int value;
        
        friend MaxStack;
    };
    
    Node * stack;
    
    public:
    
    MaxStack() { 
        stack = NULL;
    }
    
    void push (int x) {
        Node *newNode = new Node;
        newNode->value = x;
        
        if (stack == NULL) {
            stack = newNode;
            stack->next = NULL;
            stack->max = NULL;
        }
        else {
            Node *preNode = stack;
            newNode->next = stack;
            stack = newNode;
            
            if (preNode->max == NULL) {
                if (stack->value < preNode->value) {
                    stack->max = preNode;
                }
                else {
                    stack->max = NULL;
                }    
            }
            else if (stack->value < preNode->max->value) {
                stack->max = preNode->max;
            }
            else {
                stack->max = NULL;
            }
        }
    }
    
    int pop() {
        if (stack == NULL) throw "Empty Stack";
        int val = stack->value;
        Node *tmp = stack;
        stack = stack->next;
        delete(tmp);
        return val;
    }
    
    int max() {
        if (stack == NULL) throw "Empty Stack";
        if (stack->max == NULL) return stack->value;
        return stack->max->value;
    }
};

int main()
{
    MaxStack stack;
    stack.push(1);
    cout<< stack.max() << endl;
    stack.push(2);
    cout<< stack.max() << endl;
    stack.push(3);
    cout<< stack.max() << endl;
    stack.push(8);
    cout<< stack.max() << endl;
    
    cout << "Pop: " << stack.pop() << endl;
    cout<< stack.max() << endl;
    cout << "Pop: " << stack.pop() << endl;
    cout<< stack.max() << endl;

    return 0;
}


/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class MaxStack {
    class StackNode {
        int value;
        StackNode *maxNode;
        StackNode(int value) : value(value), maxNode(NULL) {}
        
        friend MaxStack;
    };
    
    std::stack<StackNode> stack;
    
    public:
    void push(int value) {
        StackNode node(value);
        
        if (!stack.empty()) {
            StackNode *nodeTop = &stack.top();
            
            if (nodeTop->maxNode == NULL) {
                if (nodeTop->value > value) {
                    node.maxNode = nodeTop; 
                }
                else {
                    node.maxNode = NULL;
                }
            }
            else {
                if (nodeTop->maxNode->value > value) {
                    node.maxNode = nodeTop->maxNode;
                }
                else {
                    node.maxNode = NULL; 
                }
            }
        } 
        
        stack.push(node);
    }
    
    bool isEmpty() {
        return stack.empty();
    }
    
    int pop() {
        if (stack.empty()) throw "Stack Empty";
        StackNode nodeTop = stack.top();
        stack.pop();
        return nodeTop.value;
    }
    
    int max() {
        StackNode nodeTop = stack.top();
        if (nodeTop.maxNode == NULL) return nodeTop.value;
        return nodeTop.maxNode->value;
    }
};

int main()
{
    MaxStack m;
    m.push(1);
    m.push(5);
    m.push(3);
    m.push(7);
    m.push(8);
    m.push(10);
    
    while (!m.isEmpty()) {
        cout << "Max: " << m.max() << endl;
        m.pop();
    }
    
    return 0;
}




