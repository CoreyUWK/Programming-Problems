/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;


struct Node {
    int value;
    Node *next;
    Node *random;
    Node (int v, Node *n = NULL, Node *r=NULL) : value(v), next(n), random(r) {}
};


Node * clone(Node *head) {
    if (NULL == head) return NULL;
    Node *cloneHead = NULL;

    Node *cur = head;
    Node *copy = NULL;

    while (cur != NULL) {
        // Copy original node
        copy = new Node(cur->value);
        if (NULL == cloneHead) cloneHead = copy; // Track head
        
        Node *tmpOrig = cur;
        Node *tmpCopy = copy;
        
        // Update
        copy = copy->next;
        cur = cur->next;
        
        // Set orignal next to new copy node
        tmpOrig->next = tmpCopy;
        // Set random of new copy to point to orignal
        tmpCopy->random = tmpOrig;
    }

    // Construct random pointers in copy
    copy = cloneHead;
    while (copy != NULL) {
        Node *tmp = copy->random;
        cout <<  copy->next->value << endl;
        copy->random =  copy->random->random->next;
        tmp->next =  copy->next->random;
        
        copy = copy->next;
    }
    
    return *copy;
}

void print(Node *node) {
    while (node!= NULL) {
        cout << node->value << " ";
        node = node->next;
    }
}

void printR(Node *node) {
    while (node != NULL) {
        cout << node->random->value << " ";
        node = node->next;
    }
}

int main()
{
    Node *head = new Node(1, new Node(2, new Node(3, new Node(4))));
    head->random = head->next->next;
    head->next->random = head->next->next->next;
    head->next->next->random = head;
    head->next->next->next->random = head->next;
    
    Node *copy = clone(head);
    //print(copy);
    //printR(copy);
 
    return 0;
}
