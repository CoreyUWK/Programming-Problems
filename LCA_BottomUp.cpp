/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef struct Node Node;
struct Node {
    int value;
    Node *left;
    Node *right;
};

std::stack<Node*> GetPath(Node *root, Node *n) {
    std::stack<Node *> path;
    if (root == NULL) return path;
    else if (root == n) {
        path.push(n);
        return path;
    }
    
    std::stack<Node*> leftPath = GetPath(root->left, n);
    std::stack<Node*> rightPath = GetPath(root->right, n);
    
    if (!leftPath.empty()) {
        leftPath.push(root);
        return leftPath;
    }
    else if (!rightPath.empty()) {
        rightPath.push(root);
        return rightPath;
    }
    else return path;
}


Node * GetLca(Node *root, Node *a, Node *b) {
    std::stack<Node *> pathA = GetPath(root, a);
    std::stack<Node *> pathB = GetPath(root, b);
    
    if (pathA.empty() || pathB.empty()) return NULL;
    
    Node *lca = NULL;
    while (!pathA.empty() && !pathB.empty()) {
        Node * pathATop = pathA.top();
        Node * pathBTop = pathB.top();
        
        if (pathATop == pathBTop) {
            lca = pathBTop;
        }
        else break;
        
        pathA.pop();
        pathB.pop();
    }
    
    return lca;
}


Node * createNode(int val) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main()
{
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    
    Node *lca = GetLca(root, root->left->right, root->left->left);
    cout << "Lca: ";
    if (NULL == lca) cout << "NULL";
    else cout << lca->value;
    
    return 0;
}
