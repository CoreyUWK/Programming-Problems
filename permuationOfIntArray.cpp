/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <array>
using namespace std;

void swap(int a[], int i, int j)
{
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void permutation(int a[], int aLength, int start, std::vector<std::vector<int>> &results)
{
    if (start >= aLength)
    {
        std::vector<int> newResult;
        for (int i = 0; i < aLength; ++i)
        {
            newResult.push_back(a[i]);
        }
        results.push_back(newResult);
    }
    else
    {
        for (int i = start; i < aLength; ++i)
        {
            swap(a, start, i);
            permutation(a, aLength, start + 1, results);
            swap(a, start, i);
        }
    }
}  

int main()
{
    int a[3] = {1, 2, 3};
    int aLength = sizeof(a)/sizeof(int);
    std::vector<std::vector<int>> results;
    permutation(a, aLength, 0, results);
    
    cout << "permutations:" << endl;
    for (std::vector<int> val : results){
        for (int i = 0; i < aLength; ++i)
        {
            cout << val[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
