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

// Amazon Interview Set 22

// 1 - Float to Binary
bitset<sizeof(float) * CHAR_BIT> floatToBinary(float f) {
    return bitset<sizeof(float) * CHAR_BIT>(*reinterpret_cast<int*>(&f));
}

// 2 - Array to min K using heap O(logn)
std::vector<int> minK(const std::vector<int> &arr, int k) {
    // Could use make_heap or priority_queue
    priority_queue<int, vector<int>, std::greater<int>> heap(arr.begin(), arr.end());
    
    std::vector<int> minKList;
    for (int i = 0; i < k; ++i) {
        minKList.push_back(heap.top());
        heap.pop();
    }
    return minKList;
}

// 3 - Single Linked list detect loop and return size of list
struct Node { 
    int key; 
    struct Node *next; 
}; 
  
Node *newNode(int key) { 
    Node *temp = new Node; 
    temp->key = key; 
    temp->next = NULL; 
    return temp; 
} 

void printLinkedList(Node *root);

// To find loop use Floyd’s Cycle detection algorithm from start = node M
// To number of nodes in loop use Floyd’s Cycle detection from M
// To find starting node of loop increament from head and M, when equal
int linkedListSize(Node * root, Node **last) {
    int count = 0;
    Node *slow = root;
    Node *fast = root;
    *last = fast;
    
    // Find if loop and count 
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        *last = fast;
        ++count;
        if (fast == slow) {
            ++count; // add loop end
            break;
        }
    }

    if (fast == slow) {
        // count rest to start of loop node
        slow = root;
        while (slow->next != fast->next) {
            ++count;
            fast = fast->next;
            slow = slow->next;
        }
        *last = fast;
    }
    else {
        while (slow != NULL) {
            slow = slow->next;
            ++count;
        }
    }
    
    return count;
}

// 4 - linked list swap kth node from start with last
void swapK(Node **root, int k) {
    Node * last = NULL;
    int size = linkedListSize(*root, &last);
    cout << "size: " << size << endl;
    if (k > size / 2 || k < 1) {
        cout << "List is of lesser size" << endl;
        return;
    }
    
    Node *prevFirst = *root;
    Node *first = *root;
    for (int i = 1; i < k; ++i, prevFirst = first, first = first->next){}
    
    Node *second = first;
    Node *prevSecond = second;
    for (int i = 0; i < size - 2*k + 1; ++i, prevSecond = second, second = second->next) {}
    
    // swap
    cout << "prev:" << prevFirst->key << " first:" << first->key << " prev:" << prevSecond->key << " second:" << second->key << endl;
    
    if (first == second) {
        return;
    }
    if (k == 1) {
        *root = second; // set new root
        second->next = first->next;
        first->next = second->next; // to NULL
        prevSecond->next = first;
    }
    /*else if (first->next == second) {
        prevFirst->next = second;
        Node *tmp = first->next;
        first->next = second->next;
        second->next = (tmp == second) ? first : tmp;   
    }*/
    else {
        prevFirst->next = second;
        Node *tmp = second->next;
        second->next = (first->next == second) ? first : first->next;
        if (first->next != second)
        {
            prevSecond->next = first;
        }
        first->next = tmp;
    }
}

void printLinkedList(Node *root) {
    unordered_set<Node*> map;
    Node *slow = root;
    while (slow != NULL) {
        if (map.find(slow) != map.end()) {
            break;
        }
        map.insert(slow);
        cout << slow->key << " ";
        slow = slow->next;
    }
    cout << endl;
}

// 5 - find 2 numbers in Binary search tree sum to K
class BST {
    struct Node {
        int key;
        Node *left;
        Node *right;
        
        Node (int val) : key(val), left(nullptr), right(nullptr) {}
    };
    
    Node *root;
    
    void inorderPrint(Node *node) {
        if (node == nullptr) return;
        
        inorderPrint(node->left);
        cout << node->key << " ";
        inorderPrint(node->right);
    }
    
    Node * insert(Node *node, int key) {
        if (node == nullptr) {
            return new Node(key);
        }
        
        if (node->key > key) {
            node->left = insert(node->left, key);
        }
        else {
            node->right = insert(node->right, key);
        }
        
        return node;
    }
    
    void treeToList(Node *root, std::vector<int> &list) {
        if (root == nullptr) return;
        treeToList(root->left, list);
        list.push_back(root->key);
        treeToList(root->right, list);
    }
    
    public:
    BST() : root(nullptr) {}
    
    void inorderPrint() {
        inorderPrint(root);
    } 
    
    void insert(int key) {
        root = insert(root, key);
    }
    
    std::vector<int> treeToList() {
        std::vector<int> list;
        if (root == nullptr) return list;
        treeToList(root, list);
        return list;
    }
    
    std::vector<int> find2Sum(int k) {
        std::vector<int> result;
        std::vector<int> inorder = treeToList();
        int front = 0;
        int back = inorder.size() - 1;
        
        while (front < back) {
            int sum = inorder[front] + inorder[back];
            if (sum < k) {
                ++front;
            }
            else if (sum > k) {
                --back;
            }
            else {
                result.push_back(inorder[front]);
                result.push_back(inorder[back]);
                break;
            }
        }
        return result;
    }
    
};


int main()
{
    // 1
    cout << floatToBinary(1.5) << endl;
    
    // 2
    int k = 5;
    vector<int> minKList{25,15,78,3,10,22};
    minKList = minK(minKList, k);
    for (int i = 0; i < k; ++i) {
        cout << minKList[i] << " ";
    }
    cout << endl;
    
    // 3
    Node *last = NULL;
    Node *head = newNode(1); 
    //head->next = head; 
    head->next = newNode(2); 
    head->next->next = newNode(3); 
    head->next->next->next = newNode(4); 
    head->next->next->next->next = newNode(5); 
    head->next->next->next->next->next = newNode(6); 
    head->next->next->next->next->next->next = newNode(7); 
    head->next->next->next->next->next->next->next = newNode(8); 

    /* Create a loop for testing */
    //head->next->next->next->next->next->next = head->next->next; 
    
    cout << linkedListSize(head, &last) << endl;
    if (last != NULL) {
        cout << "last:" << last->key << endl;
    }
    
    // 4
    printLinkedList(head);
    swapK(&head, 5);
    printLinkedList(head);
    
    // 5
    BST tree;
    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(8);
    tree.insert(6);
    tree.insert(9);
    std::vector<int> result = tree.find2Sum(15);
    for (int v : result) {
        cout << v << " + ";
    }
    cout << endl;
    
    // 6 - copy linked list with next and rand pointers O(n)
    // 1) create array of [2 - N] containing pointers to nodes O(n) space
    // 2) create copy of nodes (value and next), and update original next to new created O(n) time
    // 3) go from original and follow next to new created and random to it's create and make pointer between these two new created O(n) time
    // 4) put orignal nexts back to way it was O(n) time
    
    return 0;
}
