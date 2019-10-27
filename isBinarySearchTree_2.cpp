/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <queue>
#include<bits/stdc++.h> 
using namespace std;

class Tree 
{
    class Node 
    {
        int value;
        Node *left;
        Node *right;
        
        Node (int value) : value(value), left(NULL), right(NULL) {}
        Node (int value, Node *left, Node *right) : value(value), left(left), right(right) {}
        
        friend Tree;
    };
    
    Node *top;
    
    bool isBstInner(Node *cur, int min, int max)
    {
        if (NULL == cur)
        {
            return true;
        }
        
        if (cur->value < min || cur->value > max)
        {
            return false;
        }
        
        return isBstInner(cur->left, min, cur->value - 1) || isBstInner(cur->right, cur->value + 1, max);
    }
    
    public:
    
    Tree (int value)
    {
        top = new Node(value);
    }
    
    Tree (Tree *tree)
    {
        top = new Node (tree->top->value, tree->top->left, tree->top->right);
    }
    
    Tree (int value, Tree *left, Tree *right)
    {
        top = new Node (value, left->top, right->top);
    }
    
    void PrintTree()
    {
        if (NULL == top)
        {
            return;
        }
        
        std::queue<Node *> heap;
        heap.push(top);
        heap.push(NULL);
        bool lastNull = false;
        
        while (!heap.empty())
        {
            // Get and remove top entry
            Node *front = heap.front();
            heap.pop();
            
            // Check if NULL entry for new line (per row) and readd 
            if (front == NULL)
            {
                if (lastNull)
                {
                    break;
                }
                heap.push(NULL);
                cout << endl;
                lastNull = true;
                continue;
            }
            lastNull = false;
            
            // Output entry
            cout << front->value;
            
            if (NULL != front->left)
            {
                heap.push(front->left);
            }
            
            if (NULL != front->right)
            {
                heap.push(front->right);
            }
        }
    }
    
    bool isBst()
    {
        return isBstInner(top, INT_MIN, INT_MAX);
    }
};

int main()
{
    Tree tree = new Tree(5, 
        new Tree(2, new Tree(1), new Tree(3)), 
        new Tree(7, new Tree(6), new Tree(8)));
    tree.PrintTree();
    
    cout << ((tree.isBst()) ? "true" : "false");
    
    return 0;
}
