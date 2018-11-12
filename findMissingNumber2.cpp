/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


int oneMissing(std::vector<int> arr) {
    int totalXor = 0;
    int arrXor = 0;
    
    for (int i = 1; i <= arr.size() + 1; ++i) {
        totalXor ^= i;
    }
    
    for (int i : arr) {
        arrXor ^= i;
    }
    
    return totalXor ^ arrXor;
}

std::vector<int> twoMissing(std::vector<int> arr) {
    int totalSum = 0;
    int arrSum = 0;
    int missingSum = 0;
    int size = arr.size() + 2;
    
    for (int i = 1; i <= size; ++i) {
        totalSum += i;
    }
    
    for (int i : arr) {
        arrSum += i;
    }
    
    missingSum = totalSum - arrSum;
    int pivot = missingSum / 2;
    
    int totalLeftXor = 0;
    int totalRightXor = 0;
    int arrLeftXor = 0;
    int arrRightXor = 0;
    for (int i = 1; i <= pivot; ++i) totalLeftXor ^= i;
    for (int i = pivot + 1; i <= size; ++i) totalRightXor ^= i;
    for (int i : arr) {
        if (i <= pivot) arrLeftXor ^= i;
        else arrRightXor ^= i;
    }
    
    return {totalLeftXor ^ arrLeftXor, totalRightXor ^ arrRightXor};
}


int main()
{
    std::vector<int> arr1 = {1,2,4,5};
    cout << oneMissing(arr1) << endl;
    
    std::vector<int> arr2 = {1,3,5};
    std::vector<int> ret = twoMissing(arr2);
    cout << ret[0] << " " << ret[1] << endl;
    
    return 0;
}
