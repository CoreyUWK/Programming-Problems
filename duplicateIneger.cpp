/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;


/*
[-1,-2,4,-4] N=4
*/

std::vector<int> findAllDuplicated(int arr[], int length) {
    std::vector<int> dup;
    for (int i = 0; i < length; ++i) {
        int index = abs(arr[i]) - 1;
        if (arr[index] > 0) {
            arr[index] *= -1;
        }
        else {
            dup.push_back(abs(arr[i]));
        }
    }   
    return dup;
}

int main()
{
    int a[] = {1,2,4,4};
    std::vector<int> dup = findAllDuplicated(a, 4);
    for (int val : dup) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
