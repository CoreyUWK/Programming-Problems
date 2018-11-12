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
#include <stdio.h>
#include <string.h>
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


int sumOfPrimes(int n) {
    bool primes[n + 1];
    memset(primes, true, n + 1);
    
    for (int p = 2; p <= n; ++p) {
        if (primes[p] == true) {
            for (int mp = p * 2; mp <=n; mp += p) {
                primes[mp] = false;
            }
        }
    }
    
    int sum = 0;
    for (int i = 2; i <= n; ++i) {
        if (primes[i]) {
            sum += i;
        }
    }
    
    return sum;
}

int main ()
{
    int n = 11;
    cout << sumOfPrimes(n);

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
