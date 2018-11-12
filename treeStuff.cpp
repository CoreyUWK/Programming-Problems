/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <queue>
#include <limits>
using namespace std;

struct Node {
    int value;
    Node *left;
    Node *right;
    Node *nextRight;
    
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

void connectNodesSameLevel(Node *root) {
    std::queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while (!q.empty()) {
        Node *p = q.front();
        q.pop();
        
        if (p != NULL) {
            p->nextRight = q.front();
            
            if (p->left) q.push(p->left);  
            if (p->right) q.push(p->right);
        }
        else if (!q.empty()) {
            q.push(NULL);
        }
    }
}

void printRight(Node *root) {
    if (root == NULL) return;
    cout << root->value << " ";
    printRight(root->nextRight);
}

void printRightMain(Node *root) {
    while (NULL != root) {
        printRight(root);
        cout << endl;
        root = root->left;
    }
}

// O(n^2) space and time
std::vector<Node*> getPath(Node *root, int a, std::vector<Node*> path) {
    if (root == NULL) return std::vector<Node*>();
    path.push_back(root);
    if (root->value == a) {
        return path;
    }
    
    std::vector<Node*> pathleft = getPath(root->left, a, path);
    std::vector<Node*> pathRight = getPath(root->right, a, path);
    
    return (pathleft.empty()) ? pathRight : pathleft;
}

Node* lca(Node *root, int a, int b) {
    std::vector<Node*> pathA = getPath(root, a, std::vector<Node*>());
    std::vector<Node*> pathB = getPath(root, b, std::vector<Node*>());
    
    if (pathA.empty() || pathB.empty()) return NULL;
    
    Node *ancestor = NULL;
    for (int i = 0; i < pathA.size() && i < pathB.size() && pathA[i] == pathB[i]; ancestor = pathA[i], ++i) {}
    return ancestor;
}

// O(height of tree) + O(1-iterative, h-recursive stack)
Node *lcaBstRecursive(Node *root, int a, int b) {
    if (root == NULL) return NULL;
    
    if (a < root->value && b < root->value) {
        return lcaBstRecursive(root->left, a, b);
    }
    else if (a > root->value && b > root->value) {
        return lcaBstRecursive(root->right, a, b);
    }
    
    return root;
}

Node *lcaBstIterative(Node *root, int a, int b) {
    while (root != NULL) {
        if (a < root->value && b < root->value) {
            root = root->left;
        }
        else if (a > root->value && b > root->value) {
            root = root->right;
        }
        else {
            break;
        }        
    }
    
    return root;
}

bool isBst(Node *root, int min, int max) {
    if (root == NULL) return true;
    if (root->value < min || root->value > max) return false;
    
    return isBst(root->left, min, root->value - 1) && isBst(root->right, root->value + 1, max);
}

int main()
{
    Node * root = new Node(23);
    
    root->left = new Node(15);
    root->right = new Node(50);
    
    root->left->left = new Node(5);
    root->left->right = new Node(20);
    root->right->left = new Node(40);
    root->right->right = new Node(60);
    
    root->left->left->left = new Node(1);
    root->left->left->right = new Node(10);
    root->left->right->left = new Node(18);
    root->left->right->right = new Node(21);
    root->right->left->left = new Node(30);
    root->right->left->right = new Node(45);
    root->right->right->left = new Node(55);
    root->right->right->right = new Node(70);
    
    LevelOrder(root);
    cout << endl;
    
    LevelOrder2(root);
    cout << endl;
    
    connectNodesSameLevel(root);
    printRightMain(root);
    cout << endl;
    
    cout << lca(root, 5, 20)->value << endl;
    cout << lcaBstRecursive(root, 5, 20)->value << endl;
    cout << lcaBstIterative(root, 5, 20)->value << endl;

    cout << isBst(root, numeric_limits<int>::min(), numeric_limits<int>::max());
    return 0;
}
