/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <chrono>
#include <queue>
using namespace std;


int getParent(int child) {
    return ((child + 1) / 2) - 1;
}

int getChildLeft(int parent) {
    return (parent * 2) + 1;
}

int getChildRight(int parent) {
    return (parent * 2) + 2;
}

/*

void diagonalPrintUtil(Node *root, int d, std::vector<std::vector<int>> &diagonalPrint) {
    if (root == NULL) return;
    
    diagonalPrint[d].push_back(root->data);
    diagonalPrintUtil(root->left, d + 1, diagonalPrint);
    diagonalPrintUtil(root->right, d, diagonalPrint);
}


void diagonalPrint(Node *root) {
    std::vector<std::vector<int>> diagonalPrint;
    diagonalPrintUtil(root, 0, diagonalPrint);
    
    for (int i = 0; i < diagonalPrint.size(); ++i) {
        for (int j = 0; j < diagonalPrint[i].size(); ++j) {
            cout << diagonalPrint[i][j];
        }
        cout << endl;
    }
}

*/
void Diag(const std::vector<int> &tree)
{
    std::queue<int> queue;
    queue.push(0);
    queue.push(-1);
    
    while (!queue.empty()) 
    {
        int i = queue.front();
        queue.pop();
        
        if (-1 == i) {
            if (queue.empty())
            {
                return;
            }
            else 
            {
                cout << endl;
                queue.push(-1);
            }
        }
        else 
        {
            while (i < tree.size() && tree[i] != -2) 
            {
                cout << tree[i];
                
                int left = getChildLeft(i);
                if (left < tree.size())
                {
                    queue.push(left);
                }
                
                i = getChildRight(i);
            }
        }
    }
}


int main()
{
    /*
        8
       / \
      3   10
     /   /  \
    1   6   14
       / \  /
      4  7 13
    
    8 10 14
    3 6 7 13
    1 4 
    */
    std::vector<int> tree{8,3,10,1,-2,6,14,-2,-2,-2,-2,4,7,13};
    Diag(tree);
    return 0;
}
