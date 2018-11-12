/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// bags of chocolets, kid eats a bag/sec, wizard half fills/sec, how much in x sec kid eats.
int countChocolates(std::vector<int> bags, int sec) {
    // Form priority queue
    priority_queue<int> maxHeap(bags.begin(), bags.end()); // O(nlogn)
    int count = 0;
    
    for (int i = 0; i < sec && !maxHeap.empty(); ++i) { //O(sec)
        int bag = maxHeap.top(); 
        maxHeap.pop(); //O(logn)
        count += bag;
        bag /= 2;
        if (bag > 0) maxHeap.push(bag); //O(logn)
    }
    
    // Total is O(nlogn) + O(seclogn) = O(nlogn) 
    
    return count;
}


int main()
{
    std::vector<int> nums{2,4,6,8,9};
    cout << countChocolates(nums, 1);
    
    return 0;
}
