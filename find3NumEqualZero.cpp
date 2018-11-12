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
using namespace std;

/*
{-1, 0, 1, 2, -1, -4}
  ^  ^  ^
{-4, -1, -1, 0, 1, 2} Sorted
  ^  ^             ^
*/

std::vector<std::array<int, 3>> threeSum(int a[], int aLength)
{
    std::vector<std::array<int, 3>> results;
    std::sort(a, a + aLength);
    
    for (int i = 0; i < aLength - 3; ++i)
    {
        int start = i + 1;
        int end = aLength - 1;
        
        while (start < end)
        {
            int sum = a[i] + a[start] + a[end];
            if (sum == 0)
            {
                results.push_back( {a[i], a[start], a[end]} );
            }
            
            if (sum < 0)
            {
                ++start;
            }
            else
            {
                --end;
            }
        }
    }
    
    return results;
}

/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
#include <limits>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

std::vector<std::vector<int>> threeSum(std::vector<int> arr) {
    std::sort(arr.begin(), arr.end());
    std::vector<std::vector<int>> result;
    
    for (int i = 0; i < arr.size() - 2; ++i) {
        if (i == 0 || arr[i] > arr[i - 1]) {
            int start = i + 1;
            int end = arr.size() - 1;
            
            while (start < end) {
                int sum = arr[i] + arr[start] + arr[end];
                if (sum == 0) {
                    result.push_back({arr[i], arr[start], arr[end]});
                    
                    int currentStart = start;
                    while (arr[start] == arr[currentStart] && start < end) ++start;
                }
                else if (sum < 0) {
                    int currentStart = start;
                    while (arr[start] == arr[currentStart] && start < end) ++start;
                }
                else {
                    int currentEnd = end;
                    while (arr[end] == arr[currentEnd] && start < end) --end;
                }
            }
        }
    }
    return result;
}


int main()
{
    std::vector<std::vector<int>> result = threeSum({-1,0,1,2,-1,-4});
    for (auto v: result) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    
    return 0;
}


int main()
{
    int a[] = {-1, 0, 1, 2, -1, -4};
    int aLength = sizeof(a)/sizeof(int);
    
    std::vector<std::array<int, 3>> results = threeSum(a, aLength);
    for (auto item : results)
    {
        std::cout << item[0] << " " << item[1] << " " << item[2] << std::endl;
    }
    
    return 0;
}
