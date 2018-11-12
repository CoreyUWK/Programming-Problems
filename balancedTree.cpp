/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <array>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <cmath>
using namespace std;

/*

*/


// Height from bottom up
int balancedHeight(Node *node)
{
    if (node == NULL) return 0;
    
    int h1 = balancedHeight(node.left);
    int h2 = balancedHeight(node.right);
    
    if (h1 == -1 || h2 == -1) return -1;
    if (abs(h1 - h2) > 1) return -1;
    
    return (h1 > h2) ? h1 : h2;
}

// is every sumtree isBalanced
bool isBalanced(Node *node)
{
    int h = balancedHeight(node);
    return (h == -1) ? false : true; 
}


int main()
{
    int a[] = {1, 2, -5, 1, 2, -1};
    int aLength = sizeof(a)/sizeof(int);
    
    std::vector<int> result;
    zeroSum(a, aLength, result);
    for (int i : result)
    {
        cout << i << " ";
    }

    return 0;
}
