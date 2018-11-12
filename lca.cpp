/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <queue>
#include <bits/stdc++.h>
#include <queue>
#include <functional>
using namespace std;


bool getPath(std::vector<int> tree, int v, int i, stack<int> &path) {
    if (i >= tree.size()) return false;
    
    if (tree[i] == v) {
        path.push(v);
        return true;
    }
    
    bool inLeft = false, inRight = false;
    if (true == (inLeft = getPath(tree, v, 2*i + 1, path))) {
        path.push(tree[i]);
    }
    else if (true == (inRight = getPath(tree, v, 2*i + 2, path))) {
        path.push(tree[i]);
    }
    
    return inLeft || inRight;
}

int lca(std::vector<int> tree, int a, int b) {
    // get path to a
    std::stack<int> pathA;
    bool findA = getPath(tree, a, 0, pathA);
    
    // get path to b
    std::stack<int> pathB;
    bool findB = getPath(tree, b, 0, pathB);
    
    int lcaNode = -1;
    if (findA && findB) {
        int length = std::min(pathA.size(), pathB.size());
        for (int i = 0; i < length; ++i) {
            if (pathA.top() == pathB.top()) {
               lcaNode = pathA.top();
               pathA.pop();
               pathB.pop();
            }
            else {
                break;
            }
        }
    }
    
    return lcaNode; 
}

int main()
{
    std::vector<int> tree{1, 2, 3, 4, 5, 6, 7};
    cout << lca(tree, 6,7) << endl;
    return 0;
}
