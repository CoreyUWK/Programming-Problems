/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

// TODO use to smart pointer
// and add more members
class Tree {
    struct Node {
        Node *left;
        Node *right;
        int key;
    
        Node(int value) : key(value), left(NULL), right(NULL) {}
    };
    
    Node *root;
    
    void insert(int value, Node **x) {
        if (NULL == *x) {
            *x = new Node(value);
            return;
        }
        
        if (value <= (*x)->key) {
            insert(value, &((*x)->left));
        }
        else { // > greater
            insert(value, &((*x)->right));
        }
    }
    
    public:
    /*~Tree() {
        while (NULL != root) remove(root);
    }*/
    
    Node * getRoot() { return root; }
    
    Tree(int value) {
        root = new Node(value);
    }
    
    void insert(int value) {
        insert(value, &root);
    }
    
    // Also inorder
    static void printDepthFirst(Node * root) {
        if (NULL == root) return;
        printDepthFirst(root->left);
        cout << root->key << " ";
        printDepthFirst(root->right);
    }
    
    // Level order
    static void printBreathFirst(Node * root) {
        if (NULL == root) return;
        
        queue<Node *> fifo;
        fifo.push(root);
        while (!fifo.empty()) {
            Node * top = fifo.front();
            fifo.pop();
            
            cout << top->key << " ";
            if (NULL != top->left)
                fifo.push(top->left);
            if (NULL != top->right)
                fifo.push(top->right);
        }
    }
};

int main()
{
    Tree t(7);
    t.insert(5);
    t.insert(9);
    t.insert(3);
    t.insert(6);
    t.insert(8);
    t.insert(10);
    
    Tree::printDepthFirst(t.getRoot());
    cout << endl;
    Tree::printBreathFirst(t.getRoot());
    cout << endl;

    return 0;
}
