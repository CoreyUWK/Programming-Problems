#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <tuple>
#include <numeric>
#include <unordered_map>
using namespace std;

struct Tree {
    public:
    struct Node {
        public:
        int value;
        Node *left;
        Node *right;
        
        Node (int v, Node *l = NULL, Node *r = NULL) : value(v), left(l), right(r) {}
    };
    
    Node *root;
    Tree() : root(NULL) {}
    
    bool findDelete(int sum, Node *cur, bool &deleted) {
        if (cur == NULL && sum != 0) return false;
        if (cur == NULL && sum == 0) return true;
        
        bool foundLeft = findDelete(sum - cur->value, cur->left, deleted);
        bool foundRight = findDelete(sum - cur->value, cur->right, deleted);
        
        deleted = (foundLeft || foundRight || deleted);
        
        if (foundLeft) cur->left = NULL;
        else if (foundRight) cur->right = NULL;
        
        return foundLeft && foundRight;
    }
};

int main()
{
    Tree t;
    t.root = new Tree::Node(5, new Tree::Node(2, new Tree::Node(0, NULL, new Tree::Node(1)), new Tree::Node(4)), new Tree::Node(8, new Tree::Node(7), NULL));
    
    bool res = 0;
    t.findDelete(11, t.root, res);
    
    cout << res << endl;
    return 0;
}