/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

int minCostRecursive(std::vector<std::pair<int, int>> trips, int i, int nyCount, int sfCount) {
    if (trips.size() == i) return 0;
    
    int min = std::numeric_limits<int>::max(),
        minNy = std::numeric_limits<int>::max(), 
        minSf = std::numeric_limits<int>::max();
    
    if (nyCount < trips.size() / 2) {
        minNy = minCostRecursive(trips, i + 1, nyCount + 1, sfCount) + trips[i].first;
    }
    if (sfCount < trips.size() / 2) {
        minSf = minCostRecursive(trips, i + 1, nyCount, sfCount + 1) + trips[i].second;
    }
    
    min = std::min(minNy, minSf);
    return min;
}

bool compare (const std::pair<int, int> &lhs, const std::pair<int, int> &rhs) {
    return abs(lhs.first - lhs.second) <= abs(rhs.first - rhs.second);
}

int minCost (std::vector<std::pair<int, int>> trips) {
    // return minCostRecursive(trips, 0, 0, 0);
    int min = 0;
    int half = trips.size() / 2;
    int nyCount = 0,
        sfCount = 0;
    std::sort(trips.begin(), trips.end(), compare);
    for (int i = trips.size() - 1; i >= 0; --i) {
        if (trips[i].first < trips[i].second && nyCount < half) {
            min += trips[i].first;
            nyCount++;
        }
        else if (trips[i].second < trips[i].first && sfCount < half) {
            min += trips[i].second;
            sfCount++;
        }
        else if (nyCount < half) {
            min += trips[i].first;
            nyCount++;
        }
        else if (sfCount < half) {
            min += trips[i].second;
            sfCount++;
        }
    }

    return min;
}

int main()
{
    std::vector<std::pair<int, int>> trips = { 
        {500, 700},
        {200, 600},
        {400, 500},
        {600, 200}
    };
    
    int min = minCost(trips);
    cout << min << endl;
    return 0;
}
