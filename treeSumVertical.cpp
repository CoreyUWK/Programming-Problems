/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <stack>
#include <unordered_map>
#include <utility> 
using namespace std;

struct Node {
    int value;
    Node *left;
    Node *right;
    
    Node(int value) : value(value), left(NULL), right(NULL) {}
};

Node* createNode(int value) {
    Node *node = new Node(value);
    return node;
}

class Tree {
	void verticalSum2(int vertical, Node *node, unordered_map<int, int> &hash) {
        if (NULL == node) return;
        
        hash[vertical] += node->value;
        verticalSum(vertical - 1, node->left, hash);
        verticalSum(vertical + 1, node->right, hash);
    }

	void width2(Node *node, int level, unordered_map<int,int> &levelSum) {
        if (NULL == node) return;
        
        levelSum[level] += 1;
        width2(node->left, level + 1, levelSum);
        width2(node->right, level + 1, levelSum);
    }

    public:
    Node *root;
    Tree() : root(NULL) {}
    
    int verticalSum(int vertical) {
        if (NULL == root) return 0;
        int startVertical = 0;
        std::stack<std::pair<int, Node *>> vStack; // Stack of <virtical, Node>
        unordered_map<int, int> hash; // hash of sums <virtical, sum>
        
        // push root to stack
        vStack.push(make_pair(startVertical, root));
        
        // go through stack 
        while (!vStack.empty()) {
            auto pair = vStack.top();
            vStack.pop();
            
            hash[pair.first] += pair.second->value;
            
            if (NULL != pair.second->left) {
                vStack.push(make_pair(pair.first - 1, pair.second->left));
            }
            if (NULL != pair.second->right) {
                vStack.push(make_pair(pair.first + 1, pair.second->right));
            }
        }
        
        if (hash.find(vertical) == hash.end()) {
            return 0;
        }
        else return hash[vertical];
    }

	int verticalSum2(int vertical) {
        unordered_map<int, int> hash; // hash of sums <virtical, sum>
        verticalSum2(0, root, hash);
        
        if (hash.find(vertical) == hash.end()) {
            return 0;
        }
        else return hash[vertical];
    }

	int width2() {
        if (NULL == root) return 0;
        unordered_map<int,int> levelSum;
        width2(root, 0, levelSum);
        
        int maxWidth = 0;
        for (int i = 0; i < levelSum.size(); ++i) {
            maxWidth = std::max(maxWidth, levelSum[i]);
        }
        
        return maxWidth;
    }

    int width3() {
        std::queue<pair<Node *, int>> q;
        int maxWidth = 0;
        int level = -1;
        q.push(make_pair(root, 0));

        while (!q.empty()) {
            auto top = q.front();            
            if (level != top.second){
                level = top.second;
                if (maxWidth < q.size()) {
                    maxWidth = q.size();
                }
            }
            q.pop();
            if (NULL != top.first->left) {
                q.push(make_pair(top.first->left, top.second + 1));
            }
            if (NULL != top.first->right) {
                q.push(make_pair(top.first->right, top.second + 1));
            }
        }
        return maxWidth;
    }
};


int main()
{
    Tree t;
    t.root = createNode(1);
    
    t.root->left = createNode(2);
    t.root->right = createNode(3);
    
    t.root->left->left = createNode(4);
    t.root->left->right = createNode(5);
    
    t.root->right->left = createNode(7);
    t.root->right->right = createNode(6);
    
    cout << "Sum for 0 is " << t.verticalSum(0) << endl;
    cout << "Sum for 1 is " << t.verticalSum(1) << endl;
    cout << "Sum for -1 is " << t.verticalSum(-1) << endl;
    cout << "Sum for 2 is " << t.verticalSum(2) << endl;

	cout << "Max width: " << t.width() << endl;
    cout << "Max width: " << t.width2() << endl;

    return 0;
}




/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <stack>
#include <unordered_map>
#include <utility> 
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

struct Node {
    int value;
    Node *left;
    Node *right;
    
    Node(int value) : value(value), left(NULL), right(NULL) {}
};

Node* createNode(int value) {
    Node *node = new Node(value);
    return node;
}

class Tree {
    void verticalSumInter(Node *node, int v, unordered_map<int, int> &map) {
        if (NULL == node) return;
        
        map[v] += node->value;
        verticalSumInter(node->left, v - 1, map);
        verticalSumInter(node->right, v + 1, map);
    }
    
    void maxWidthInter(Node *node, int level, unordered_map<int,int> &map) {
        if (NULL == node) return;

        map[level] += 1;
        maxWidthInter(node->left, level + 1, map);
        maxWidthInter(node->right, level + 1, map);
    }
    
    static bool widthCompare(pair<int,int> lhs, pair<int,int> rhs) {
        return rhs.second > lhs.second;
    }
    
    public:
    Node *root;
    Tree() : root(NULL) {}
    
    int verticalSum(int n) {
        unordered_map<int, int> map;
        verticalSumInter(root, 0, map);
        
        if (map.find(n) == map.end()) return 0;
        return map[n];
    }
    
    int maxWidth() {
        unordered_map<int, int> map;
        maxWidthInter(root, 0, map);

        return std::max_element(map.begin(), map.end(), widthCompare)->second;
    }
    
    int maxWidth2() {
        if (root == NULL) return 0;
        
        std::queue<Node*> fifo;
        
        fifo.push(root);
        fifo.push(NULL);
        
        int width = 1;
        int tmpWidth = 0;
        while(!fifo.empty()) {
            Node *top = fifo.front();
            fifo.pop();
            
            if (top == NULL) {
                width = std::max(width, tmpWidth);
                tmpWidth = 0;
                if (!fifo.empty())
                    fifo.push(NULL);
            }
            else {
                tmpWidth += 1;
                if (top->left != NULL)
                    fifo.push(top->left);
                    
                if (top->right != NULL)
                    fifo.push(top->right);
            }
        }
        return width;
    }
};

int main()
{
    Tree t;
    t.root = createNode(1);
    
    t.root->left = createNode(2);
    t.root->right = createNode(3);
    
    t.root->left->left = createNode(4);
    t.root->left->right = createNode(5);
    
    t.root->right->left = createNode(7);
    t.root->right->right = createNode(6);
    
    cout << "Sum for 0 is " << t.verticalSum(0) << endl;
    cout << "Sum for 1 is " << t.verticalSum(1) << endl;
    cout << "Sum for -1 is " << t.verticalSum(-1) << endl;
    cout << "Sum for 2 is " << t.verticalSum(2) << endl;

	cout << "Max width: " << t.maxWidth() << endl;
	cout << "Max width: " << t.maxWidth2() << endl;

    return 0;
}

