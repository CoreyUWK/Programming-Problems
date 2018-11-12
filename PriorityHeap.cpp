/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
heap [3, 4, 0, 0, 0]
size = 0

       10
     /  \
    9   8
   / \  / \
  6  7 
 
 0 1 2 3 4 5 6 
 3 4 5 6 7 8 9 
0 -> 1 2 => 0*2 + 1 | 0*2 + 2 / 1 
1 -> 3 4
2 -> 5 6
*/

class PriorityQueue {
    std::vector<int> heap;
    int size;
    
    public:
    
        PriorityQueue(int maxSize) : size(0), heap(maxSize) {}
        
        void push(int value) {
            int pos = size;
            heap[pos] = value;
            
            // Bubble up value
            while (pos > 0) {
                int parent = ((pos + 1) / 2) - 1;
                if (heap[parent] > heap[pos]) break;
                std::swap(heap[parent], heap[pos]);
                pos = parent;
            }
            ++size;
        }
    
        int pop() {
            if (size == 0) throw "Empty Heap";
            int toReturn = heap[0];
            heap[0] = heap[size - 1];
            
            // Bubble down value
            int pos = 0;
            while (pos < (size / 2)) {
                int leftChild = pos * 2 + 1;
                int rightChild = leftChild + 1;
                
                // Check children exist
                if (rightChild < size && heap[leftChild] < heap[rightChild]) {
                    
                    // Check right new max
                    if (heap[pos] >= heap[rightChild]) break;
                    std::swap(heap[pos], heap[rightChild]);
                    pos = rightChild;
                }
                else {
                    if (heap[pos] >= heap[leftChild]) break;
                    std::swap(heap[pos], heap[leftChild]);
                    pos = leftChild;
                }
            }
            --size;
            return toReturn;
        }
};


int main()
{
    PriorityQueue heap(100);
    heap.push(1);
    heap.push(2);
    heap.push(10);
    heap.push(7);
    
    cout << heap.pop() << endl;
    cout << heap.pop() << endl;
    cout << heap.pop() << endl;
    cout << heap.pop() << endl;

    return 0;
}
