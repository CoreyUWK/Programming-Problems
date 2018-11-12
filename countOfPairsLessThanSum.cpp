/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

// count number of pairs whos sum less than max sum
int countSumPairLess(std::vector<int> nums, int maxSum) {
    int start = 0;
    int end = nums.size() - 1;
    int count = 0;
    
    while (start < end) {
        int sum = nums[start] + nums[end];
        if (sum < maxSum) {
            count += (end - start);
            start += 1; // move to next set of pairs
        }
        else {
            end -= 1; // Sum is to large so get a smaller pair
        }
    }
    
    return count;
}

int main()
{
    std::vector<int> nums{2,4,6,8,9};
    cout << countSumPairLess(nums, 14);
    
    return 0;
}
