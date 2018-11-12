/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
1) sort list 


4 2 5 9 6

int max = 3;
int tmpMax = 0;
sorted: 2 4 5 6 9
                ^

O(nlogn + n) = O(nlogn)

2 
4 5 6 
9

2) to remove the sort time can use a hash
hash: 4 2 5 9 6 - O(n)
go through hash O(n^2)
4 5 6 
2
9

*/

int consecutive(const std::vector<int> &list) {
    std::unordered_set<int> map;
    for (int i = 0; i < list.size(); ++i) {
        map.insert(list[i]);
    }
    
    int max = 0;
    for (int i = 0; i < list.size(); ++i) {
        if (map.find(list[i] - 1) != map.end()) continue;
        
        int localMax = 1;
        int offset = 1;
        while (map.find(list[i] + offset) != map.end()) {  // Go from + 1 to end of consecutive
            ++localMax;
            ++offset;
        }
        max = std::max(max, localMax);
    }
    
    return max;
}

int main()
{
    std::vector<int> list = {4,2,1,6,5};
    cout << consecutive(list);
    return 0;
}
