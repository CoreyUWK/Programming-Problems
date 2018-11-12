/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class LinkedList {
    class Node {
        Node * next;
        int value;
        
        Node (int value) : value(value), next(NULL) {}
        
        friend LinkedList;
    };
    
    Node *head;
    Node *tail;

    public:
    
    LinkedList() : head(NULL), tail(NULL) {}
    
    void insertNode(int value) {
        if (head == NULL) {
            head = new Node(value);
            tail = head;
        }
        else {
            Node *newNode = new Node(value);
            tail->next = newNode;
            tail = tail->next;
        }
    }
    
    void insertCycle(int mToLast) {
        Node *mToLastNode = head;
        for (int i = 0; mToLastNode != NULL && i < mToLast; ++i) {
            mToLastNode = mToLastNode->next;
        }
        
        if (mToLastNode == NULL) throw "list does not contain m nodes";
        
        tail->next = mToLastNode;
    }
    
    bool hasCycle() {
        if (head == NULL) return false;
        
        Node *slow = head;
        Node *fast = head;
        
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) return true;
        }
        
        return false;
    }
    
};

int main()
{
    LinkedList list;
    list.insertNode(1);
    list.insertNode(2);
    list.insertNode(3);
    list.insertNode(4);
    list.insertNode(5);
    
    cout << list.hasCycle() << endl;
    list.insertCycle(3);
    cout << list.hasCycle() << endl;

    return 0;
}
