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

using namespace std;

typedef struct TreeNode TreeNode;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};


void treeNoRecursionPrintGoLeft(TreeNode *tree, std::stack<TreeNode *> &stack)
{
    TreeNode *treePtr = tree;
    // Go Left down the tree and push till end
    while (NULL != treePtr)
    {
        stack.push(treePtr);
        treePtr = treePtr->left;
    }
}

void treeNoRecursionPrint(TreeNode *tree)
{
    TreeNode *treePtr = tree;
    std::stack<TreeNode *> stack;
    
    // Traverse Left to last leaf
    treeNoRecursionPrintGoLeft(treePtr, stack);

    while (!stack.empty())
    {
        treePtr = stack.top();
        stack.pop();
        cout << treePtr->val;
        // Go right one
        if (NULL != treePtr->right)
        {
            treeNoRecursionPrintGoLeft(treePtr->right, stack);
        }
    }
}


void treeDepthPrint(TreeNode *tree)
{
    TreeNode *treePtr = tree;
    if (NULL == treePtr) return;
    
    treeDepthPrint(treePtr->left);
    cout << treePtr->val;
    treeDepthPrint(treePtr->right);
}


void treeLevelPrint(TreeNode *tree)
{
    std::queue<TreeNode*> queue;
    
    if (NULL == tree) return;
    queue.push(tree);
    
    while (!queue.empty())
    {
        TreeNode *treePtr = queue.front();
        queue.pop();
        cout << treePtr->val << " ";
        if (NULL != treePtr->left)
            queue.push(treePtr->left);
        if (NULL != treePtr->right)
            queue.push(treePtr->right);
    }
}


void createTree(TreeNode *tree, int levels)
{
    TreeNode *treePtr = tree;
    static int value = 1;
    if (NULL == treePtr) {
        value = 1;
        return;
    }
    if (levels == 0) {
        value = 1;
        return;
    }
    treePtr->val = value++;
    treePtr->left = NULL;
    treePtr->right = NULL;
    if (levels > 1)
    {
        treePtr->left = (TreeNode*)malloc(sizeof(TreeNode));
        createTree(treePtr->left, levels - 1);
        treePtr->right = (TreeNode*)malloc(sizeof(TreeNode));
        createTree(treePtr->right, levels - 1);
    }
}

int main()
{
    TreeNode *tree = (TreeNode*)malloc(sizeof(TreeNode));
    createTree(tree, 3);
    treeLevelPrint(tree);
	
	cout << endl;
    treeDepthPrint(tree);
	
	cout << endl;
    treeNoRecursionPrint(tree);

    return 0;
}
