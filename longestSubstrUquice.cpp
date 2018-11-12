/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;


typedef struct TreeNode TreeNode;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};




bool isBalanced(TreeNode *root) {

}

TreeNode * insert(int val) {
    TreeNode * node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int longestUniqueSubsttr(string s) {
    size_t mapLength = 1 << 8;
    int visited[mapLength];
    int curLength = 0;
    int maxLength = 0;
    
    for (int i=0; i < mapLength; ++i) {
        visited[i] = -1;
    }
    
    visited[0] = 0;
    
    for (int i = 1; i < s.length(); ++i) {
        int prevIndex = visited[s[i]];
        
        // Check if have not visited character before
        if (prevIndex == -1 || i - curLength > prevIndex ) {
            ++curLength;
        }
        else {
            if (curLength > maxLength)
                maxLength = curLength;
            curLength = i - prevIndex;
        }
        
        visited[s[i]] = i;
    }
    
    if (curLength > maxLength)
        maxLength = curLength;
                
    return maxLength;
}

int main ()
{
    string str = "ABDEFGABEF";
    cout << "The input string is " <<  str;
    int len =  longestUniqueSubsttr(str);
    cout << "\nThe length of the longest non-repeating "
           "character substring is " << len;
    return 0;
    
    TreeNode *tree = insert(1);
    tree->left = insert(2);
    tree->right = insert(3);
    tree->left->left = insert(4);
    tree->left->right = insert(5);
    tree->right->left = insert(6);
    tree->right->right = insert(7);
    
    cout << isBalanced(tree);
    
    return 0;
}
