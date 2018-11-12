/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int findFirst(const std::vector<int> &arr, int value, int low, int high) {
    if (low > high) return -1;
    
    int mid = low + (high - low) / 2;
    
    if ( (mid == 0 || arr[mid - 1] < value) && arr[mid] == value) return mid;
    else if (arr[mid] < value) return findFirst(arr, value, mid + 1, high);
    else return findFirst(arr, value, low, mid - 1);
}

int findLast(const std::vector<int> &arr, int value, int low, int high) {
    if (low > high) return -1;
    
    int mid = low + (high - low) / 2;
    
    if ( (mid == (arr.size() - 1) || arr[mid + 1] > value) && arr[mid] == value) return mid;
    else if (arr[mid] > value) return findLast(arr, value, low, mid - 1);
    else return findLast(arr, value, mid + 1, high);
}

int main()
{
    std::vector<int> arr = {1, 2, 2, 2, 2, 3, 4, 7, 8, 8};
    int first = findFirst(arr, 2, 0, arr.size() - 1);
    int second = findLast(arr, 2, 0, arr.size() - 1);
    cout << first << " " << second;
    return 0;
}
