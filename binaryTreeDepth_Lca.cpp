/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

typedef struct Node Node;
struct Node {
    int data;
    Node *left;
    Node *right;
};

Node * newNode(int data) {
    Node * newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

int maxDepth(Node *tree) {
    if (tree == NULL) return 0;
    
    int maxLeft = maxDepth(tree->left) + 1;
    int maxRight = maxDepth(tree->right) + 1;
    
    return (maxLeft > maxRight) ? maxLeft : maxRight;
}


bool getPath(Node *root, int v, vector<Node *> &path) {
    if (root == NULL) {
        path.clear();
        return false;
    }
    path.push_back(root);
    if (v == root->data) {
        return true;
    }
    else if (v < root->data) {
        getPath(root->left, v, path);
    }
    else {
        getPath(root->right, v, path);
    }
    
    return false;
}


vector<Node*> getPath(Node *root, int v) {
    vector<Node *> path;
    getPath(root, v, path);
    return path;
}


Node *lca(Node *root, int v1, int v2) {
	vector<Node*> path1 = getPath(root, v1);
    vector<Node*> path2 = getPath(root, v2);
    
    if (path1.empty() || path2.empty()) return NULL;

    int lcaIndex = 0;
    Node *lcaNode = path1[lcaIndex++];
    while (lcaNode != NULL) {
        if (path1.size() < lcaIndex + 1 ||
           path2.size() < lcaIndex + 1) {
            break;
        }
        
        Node *path1Node = path1[lcaIndex];
        Node *path2Node = path2[lcaIndex];
        ++lcaIndex;
        
        if (path1Node->data == path2Node->data) {
            lcaNode = path1Node;
        }
        else {
            break;
        }
    }
    
    return lcaNode;
}


int main()
{
    /*
        5
       / \
      3   7
     / \ / \
    1  0 6 9
    \       \
     2      10
    */
    Node *root = newNode(5);
    
    root->left = newNode(3);
    root->right = newNode(7);
    
    root->left->left = newNode(1);
    root->right->left = newNode(6);
    root->right->right = newNode(9);
    
    root->left->left->right = newNode(2);
    root->right->right->right = newNode(10);
    
    cout << maxDepth(root) << endl;
    
    Node *lcaNode = lca(root, 6, 10);
    if (NULL != lcaNode) {
        cout << lcaNode->data << endl;
    }
    else {
        cout << "NULL" << endl;
    }
    
    return 0;
}
