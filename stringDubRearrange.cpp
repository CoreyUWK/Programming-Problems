#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <tuple>
#include <numeric>
#include <unordered_map>
using namespace std;
//https://www.geeksforgeeks.org/rearrange-characters-string-no-two-adjacent/
string rearrange1(string s) {
    unordered_map<char, int> countMap;
    vector<char> orderMap;
    string out;
    
    // O(n)
    for (char c : s) {
        if (countMap.find(c) == countMap.end()) {
            orderMap.push_back(c);
            countMap[c] = 0;
        }
        countMap[c] += 1;
    }
    
    // O(n)
    while (!countMap.empty()) {
        int nextIdx = -1;
        
        // O(2)
        for (int i = 0; i < orderMap.size(); ++i) {
            if (out.back() != orderMap[i]) {
                nextIdx = i;
                break;
            }
        }
        
        if (-1 == nextIdx) {
            return "not possible";
        }
        
        out.push_back(orderMap[nextIdx]);
        --countMap[orderMap[nextIdx]];
        if (0 == countMap[orderMap[nextIdx]]) {
            countMap.erase(orderMap[nextIdx]);
            orderMap.erase(orderMap.begin() + nextIdx);
        }
    }
    
    return out;
}



int main()
{
    cout << rearrange("aaabc") << endl;
    cout << rearrange("aaabb") << endl;
    cout << rearrange("aa") << endl;
    cout << rearrange("aaaabc") << endl;
    cout << rearrange("aaaabcc") << endl;

    return 0;
}