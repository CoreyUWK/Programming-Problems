/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <array>
using namespace std;

template<int N>
int sum(const std::array<int, N> & list, unsigned int i, unsigned int j) {
    int sumIndex = 0;
    
    if (j - 1 > list.size()) return 0;
    
    // Pre-process
    std::array<int, N + 1> sumList;
    sumList[sumIndex] = 0;
    for (int val : list) {
        sumList[sumIndex + 1] = sumList[sumIndex] + val;
        ++sumIndex;
    }
    
    return sumList[j] - sumList[i];
}

int main()
{
    const int N = 5;
    std::array<int, 5> list = {1, 2, 3, 4, 5};
    cout << sum<N>(list, 1, 3);
    
    return 0;
}
