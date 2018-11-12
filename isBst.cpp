/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
#include <limits>
using namespace std;

struct TreeNode {
    TreeNode *left;
    TreeNode *right;
    int value;
};


bool isBST(TreeNode *node, int min, int max) {
    if (node == NULL) return true;
    if (node->value < min || node->value > max) return false;
    
    bool left = isBST(node->left, min, node->value - 1);
    bool right = isBST(node->right, node->value + 1, max);
    if (left == false || right == false) return false;
    
    return true;
}

bool isBST(TreeNode *root) {
    return isBST(root, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
}

TreeNode * createNode(int value) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main()
{
    /*TreeNode *root = createNode(5);
    
    root->left = createNode(2);
    root->right = createNode(7);
    
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    
    root->right->left = createNode(6);
    root->right->right = createNode(8);*/
    
    TreeNode *root = createNode(50);
    
    root->left = createNode(30);
    root->right = createNode(70);
    
    root->left->left = createNode(23);
    root->left->right = createNode(50);
    
    root->right->left = createNode(55);
    root->right->right = createNode(76);
    
    cout << isBST(root);
    
    return 0;
}
