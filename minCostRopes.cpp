/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int minCost(std::vector<int> ropes) {
    if (ropes.empty()) return 0;
    if (ropes.size() == 1) return ropes[0];
    if (ropes.size() == 2) return (ropes[0] + ropes[1]);
    
    std::sort(ropes.begin(), ropes.end());

    int coef = ropes.size() - 1;
    int cost = coef * (ropes[0] + ropes[1]);
    for (int i = 2; i < ropes.size(); ++i) {
        cost += ((--coef) * ropes[i]);
    }
    
    return cost;
}

int main()
{
    std::vector<int> ropes{4,3,2,6};
    cout << minCost(ropes);
    return 0;
}
