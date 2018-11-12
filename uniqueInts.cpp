/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

std::vector<int> unqiue(std::vector<int> list) {
    unordered_set<int> hash(list.begin(), list.end());  // O(n)
    std::vector<int> result;

    cout << list.size() << " " << hash.size() << endl;
    
    for (int i : list) {  // O(n)
        if (hash.find(i) != hash.end()) {
            result.push_back(i);
            hash.erase(i);
        }
    }
    return result;
}

int main()
{
    // 1 10 12 2 2166 3 234 4 443 43 5 53 34 6 7 8
    std::vector<int> list{1,10,1,12,2,2166,3,3,234,4,234,4,443,43,5,53,4,5,34,6,6,7,7,7,8,8,8};
    
    std::vector<int> res = unqiue(list);
    for (int i : res) {
        cout << i << " ";
    }
    
    return 0;
}
