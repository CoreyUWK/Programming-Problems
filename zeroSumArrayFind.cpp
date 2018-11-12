/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <array>
#include <stack>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
{1, 2, -5, 1, 2, -1}
 ^ 
 0  1  3  -2 -1   1   0

{0:0, 1:1:, 3:2, -2:3, -1:4
      i=1 to 5-1=4
*/

void zeroSum(int a[], int aLength, std::vector<int> &result)
{
    std::unordered_map<int, int> map;
    int sum = 0;
    for (int i = 0; i < aLength; ++i)
    {
        std::unordered_map<int,int>::const_iterator oldIndex = map.find(sum);
        if (oldIndex == map.end())
        {
            // not found
            map.insert(std::pair<int,int>(sum, i));
            sum += a[i];
        }
        else
        {
            int start = oldIndex->second;
            int end = i;
            for (int j = start; j < end; ++j)
            {
                result.push_back(a[j]);
            }
            break;
        }
    }
}

int main()
{
    int a[] = {1, 2, -5, 1, 2, -1};
    int aLength = sizeof(a)/sizeof(int);
    
    std::vector<int> result;
    zeroSum(a, aLength, result);
    for (int i : result)
    {
        cout << i << " ";
    }

    return 0;
}
