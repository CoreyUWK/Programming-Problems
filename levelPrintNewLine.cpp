/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int value;
    Node *left;
    Node *right;
    
    Node(int value, Node *left=NULL, Node *right=NULL) : value(value), 
            left(left), right(right) {}
};

int height(Node *root) {
    if (root == NULL) return 0;
    
    int lh = height(root->left);
    int rh = height(root->right);
    
    return std::max(lh, rh) + 1;
}

void printLevel(Node *root, int level) {
    if (root == NULL) return;
    if (level == 1) {
        cout << root->value << " ";
    }
    else if (level > 1) {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

// O(h*n^2) = O(n^2)
void LevelOrder(Node *root) {
    int h = height(root);
    
    for (int i = 1; i <= h; ++i) {
        printLevel(root, i);
        cout << endl;
    }
}

// O(n)
void LevelOrder2(Node *root) {
    if (root == NULL) return;
    std::queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        int count = q.size();
        
        while (count > 0) {
            Node *top = q.front();
            q.pop();
            cout << top->value << " ";
            if (top->left != NULL) q.push(top->left);
            if (top->right != NULL) q.push(top->right);
            --count;
        }
        cout << endl;
    }
}

int main()
{
    Node * root = new Node(20, 
                new Node(8, 
            new Node(4), new Node(12, new Node(10), new Node(14))), new Node(22));
    LevelOrder(root);
    LevelOrder2(root);
    return 0;
}
