/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

typedef struct Node Node;
struct Node {
    int data;
    Node *left;
    Node *right;
};


int height(Node *tree) {
    if (tree == NULL) return 0;
    
    return 1 + std::max(height(tree->left), height(tree->right));
}


bool isBalanced(Node *tree) {
    if (tree == NULL) return true;
    
    int heightLeft = height(tree->left);
    int heightRight = height(tree->right);
    
    if (std::abs(heightLeft - heightRight) <= 1 && 
        isBalanced(tree->left) && isBalanced(tree->right)) {
            return true;
    }
    else {
        return false;
    }
}

// another 
int isBalanced2(Node *root) {
    if (root == NULL) return 0;
    int heightL = isBalanced(root->left);
    int heightR = isBalanced(root->right);
    
    if (heightL == -1 || heightR == -1) return -1;
    else if (abs(heightL - heightR) > 1) {
        return -1;
    }
    return std::max(heightL, heightR) + 1;
}


Node * newNode(int data) {
    Node * newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

int main()
{
 /*
        5
       / \
      3   7
     / \ / \
    1  4 6  9
    \       \
     2      10
    */
    Node *root = newNode(5);
    
    root->left = newNode(3);
    root->right = newNode(7);
    
    root->left->left = newNode(1);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(9);
    
    root->left->left->right = newNode(2);
    root->right->right->right = newNode(10);
    
    cout << isBalanced(root);
    
    return 0;
}
