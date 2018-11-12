/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

typedef struct Node Node;
struct Node {
    int data;
    Node *left;
    Node *right;
};

Node * newNode(int data) {
    Node * newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

int maxDepth(Node *tree) {
    if (tree == NULL) return 0;
    
    int maxLeft = maxDepth(tree->left) + 1;
    int maxRight = maxDepth(tree->right) + 1;
    
    return (maxLeft > maxRight) ? maxLeft : maxRight;
}

int main()
{
    /*
        5
       / \
      3   7
     / \ / \
    1  0 0 9
    \       \
     2      10
    */
    Node *root = newNode(5);
    
    root->left = newNode(3);
    root->right = newNode(7);
    
    root->left->left = newNode(1);
    root->right->right = newNode(9);
    
    root->left->left->right = newNode(2);
    root->right->right->right = newNode(10);
    
    cout << maxDepth(root);

    return 0;
}
