/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/* Analysis:
    Version 1 (Interview Code):
        Sorted on insert O(n)
        Print just prints O(n)
    
    Version 2: 
        - uses a vector/array to link sorted lists (min and max) to list node pointers
        - Extra memory O(2n + 2) ~= O(n)
        - Insert just inserts O(1)
        - Print performs partial sort if have not sorted list already for the requested amount
            - O(nlogn)
        - Here underlying linked list still exists not inorder
            
    Version 3: 
        - If use sorted set(hash) instead of vectors
            - So Extra memory O(2n) better?
            - Insert will insert into ordered set O(logn) - binary search tree
            - Print will just print O(n)
        - Here underlying linked list still exists not inorder 
        - Set for node pointers, will have custom compare to compare node values (similar to version 2)
        
    Would have to check with client which one is best or if another version would be perferred, though
    if another is perferred than possible linked list is not what customer wants (maybe just use binary search tree
    or use stl/third party data structure library)
*/
    
    
class SortedLinkedList {
    protected:
    class Node {
        public:
            int value;
            Node *next;
        
        Node() : value(0), next(NULL) {}
        Node(int value) : value(value), next(NULL) {}
    };
    
    private:
    Node *head = NULL;
    Node *tail = NULL;
    std::vector<Node *> sortedListMin;
    std::vector<Node *> sortedListMax;
    unsigned int sortedListMinCount;
    unsigned int sortedListMaxCount;
    
    static bool sortCompareMin(const Node * const lhs, const Node * const rhs) {
        return lhs->value < rhs->value;
    }
    
    static bool sortCompareMax(const Node * const lhs, const Node * const rhs) {
        return lhs->value > rhs->value;
    }
    
    public:
        SortedLinkedList() : head(NULL), tail(NULL), sortedListMinCount(0), sortedListMaxCount(0) {}  
        ~SortedLinkedList() {
            sortedListMin.clear();
            sortedListMax.clear();
            sortedListMinCount = 0;
            sortedListMaxCount = 0;
            
            while (NULL != head) {
                Node *next = head->next;
                delete head;
                head = next;
            }
            tail = head;
        }
        // void remove();

        bool isEmpty() { return (NULL == head); }
        unsigned int size() { 
            // Could return any of the potential variables
            return sortedListMin.size();
        }
        
        void insert(int value) {
            Node *newNode = new Node(value);

            if (isEmpty()) {
                head = tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = tail->next;
            }
            
            sortedListMin.push_back(newNode);
            sortedListMax.push_back(newNode);
        }
        
        void minPrint(int n) {
            n = std::min(sortedListMin.size(), (size_t)n);
            if (0 == n) return;
            
            if (sortedListMinCount < n) {
                std::partial_sort(sortedListMin.begin(), sortedListMin.begin() + n, sortedListMin.end(), sortCompareMin);
                sortedListMinCount = n;
            }
            
            for (int i = 0; i < n; ++i) {
                printf("[%d]=%d", i, sortedListMin[i]->value);
                if (i + 1 < n) {
                    cout << " -> ";
                }
            }
            cout << endl;
        }
        
        void maxPrint(int n) {
            n = std::min(sortedListMax.size(), (size_t)n);
            if (0 == n) return;
            
            if (sortedListMaxCount < n) {
                std::partial_sort(sortedListMax.begin(), sortedListMax.begin() + n, sortedListMax.end(), sortCompareMax);
                sortedListMaxCount = n;
            }
            
            for (int i = 0; i < n; ++i) {
                printf("[%d]=%d", i, sortedListMax[i]->value);
                if (i + 1 < n) {
                    cout << " -> ";
                }
            }
            cout << endl;
        }
};


int main()
{
    SortedLinkedList list;
    
    list.insert(7);
    list.insert(3);
    list.insert(1);
    list.insert(5);
    list.insert(8);
    list.insert(9);
    
    cout << "Size: " << list.size() << endl;
    
    for (int i = 0; i < list.size() + 3; ++i)
    {
        printf("Print Min:%d\n", i);
        list.minPrint(i);
        printf("Print Max:%d\n", i);
        list.maxPrint(i);
    }

    return 0;
}
