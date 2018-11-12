/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

template <class T>
class miniVector {
    int capacity; // Size of array
    int size; // Number of elements in array
    T *arr; // Dynamically allocated array
    
    public:
    T& operator[] (unsigned int i);
    void reserve(int capacity, bool copy);
    void push_back(const T& item);
};

template <class T>
T& miniVector<T>::operator [] (unsigned int i) {
   assert( (i >= 0) && (index < size));
   return arr[i]; 
}

template <class T>
void miniVector<T>::reserve(int capacity, bool copy) {
    T *newArr = NULL;
    int i;
    
    // allocate new array
    newArr = new T[capacity];
    if (newArr == NULL) {
        throw memoryAllocationError("miniVector reserve(): memory allocation failure");
    }
    
    // if copy true then copy elements
    if (copy) {
        for (i = 0; i < size; ++i) {
            newArr[i] = arr[i];   
        }
    }
    
    // Delete original array
    if (arr != NULL)
        delete [] arr;
    
    // Update state
    this.capacity = capacity;
    arr = newArr;
}

template <class T>
void miniVector<T>::push_back(const T& item) {
    // If array full allocate more capacity
    if (size == capacity) {
        if (capacity == 0) {
            // if capacity is 0, set capacity to 1
            // set copy to false beause there are 
            // no existing elements
            reserve(1,false);
        }
        else {
            // double capacity
            reserve(capacity * 2, true);
        }
    }
    
    // Add item to array list and update state
    arr[size] = item;
    --capacity;
    ++size;
}

int main()
{
    cout<<"Hello World";

    return 0;
}
