/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;

#define INT_MAX (numeric_limits<int>::max())

// O(2^(dest-1)) or O(2^n) time as running over n and each time splitting into two recursive calls
int minCostRecursion(const std::vector<std::vector<int>> &cost, int source, int dest) {
    //cout << source << " " << dest << endl;

    if (source >= cost.size() || dest >= cost.size()) return 0;
    if (source == dest) return cost[source][dest];
    if (source + 1 == dest) return cost[source][dest];
    
    int min = cost[source][dest]; // get direct
    
    // get indirect
    for (int i = source + 1; i < dest; ++i) {
        int tmpCost = minCostRecursion(cost, source, i) + minCostRecursion(cost, i, dest);
        min = std::min(min, tmpCost); // take min
    }
    
    return min;
}

// O(n^2) space and O(n^2) time
int minCostDp(std::vector<std::vector<int>> cost, int source, int dest) {
    int cache[cost.size()][cost.size()];
    
    // Initalize
    for (int i = source; i < dest; ++i) {
        for (int j = i + 1; j <= dest; ++j) {
            // cout << i << " " << j << endl;
            cache[i][j] = cost[i][j];
        }
    }
    
    // find min
    for (int i = source + 1; i < dest; ++i) {
        for (int j = i + 1; j <= dest; ++j) {
            cache[i][j] = std::min(cache[i - 1][j], cache[i][j] + cache[i - 1][i]); // j - (j - i) = i
            // cout << i << " " << j << " " << cache[i][j] << endl;
        }
    }
    return cache[dest - 1][dest];
}

// O(n) space and O(n^2) time
int minCostDp2(std::vector<std::vector<int>> cost, int source, int dest) {
    int cache[cost.size()];
    cache[0] = 0;
    for (int i = 1; i < cost.size(); ++i) {
        cache[i] = INT_MAX;
    }
    
    for (int i = source; i < dest; ++i) {
        for (int j = i + 1; j <= dest; ++j) {
            //cout << cache[j] << " " <<  cost[i][j] + cache[i] << endl;
            cache[j] = std::min(cache[j], cost[i][j] + cache[i]); // j - (j - i) = i
        }
    }

    return cache[dest];
}


int main()
{
    std::vector<std::vector<int>> cost{
        {0, 15, 80, 90},
        {INT_MAX, 0, 40, 50},
        {INT_MAX, INT_MAX, 0, 70},
        {INT_MAX, INT_MAX, INT_MAX, 0}
    };
    cout << minCostRecursion(cost, 0, cost.size() - 1) << endl;
    cout << minCostDp(cost, 0, 3) << endl;
    cout << minCostDp2(cost, 0, 3) << endl;
    return 0;
}
