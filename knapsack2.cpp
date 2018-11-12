/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <forward_list>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;

int Knapsack(int maxWeight, std::vector<int> weights, std::vector<int> values, int index) {
    if (index >= weights.size()) return 0;
    
    int costWith = 0;
    int costWithout = Knapsack(maxWeight, weights, values, index + 1);
    if (maxWeight >= weights[index]) {
        costWith = Knapsack(maxWeight - weights[index], weights, values, index + 1) + values[index];
    }
    
    return std::max(costWith, costWithout);
}

int Knapsack(int maxWeight, std::vector<int> weights, std::vector<int> values) {
    if (weights.size() != values.size()) throw std::invalid_argument("");
    return Knapsack(maxWeight, weights, values, 0);
}

int KnapsackCache(int maxWeight, std::vector<int> weights, std::vector<int> values) {
    int cache[weights.size() + 1][maxWeight + 1];
    memset(cache, 0, sizeof(cache));
    
    for (int w = 1; w <= weights.size(); ++w) {
        for (int mw = 1; mw <= maxWeight; ++mw) {
            if (mw >= weights[w-1]) {
                cache[w][mw] = std::max(values[w - 1] + cache[w - 1][mw - weights[w - 1]],
                    cache[w - 1][mw]);
            }
            else {
                cache[w][mw] = cache[w - 1][mw];
            }
        }
    }
    
    return cache[weights.size()][maxWeight];
}

int main()
{
    std::vector<int> weights = {1,2,3};
    std::vector<int> values = {6,10,12};
    int maxValue = Knapsack(5, weights, values);
    cout << maxValue << endl;
    
    maxValue = KnapsackCache(5, weights, values);
    cout << maxValue << endl;

    return 0;
}
