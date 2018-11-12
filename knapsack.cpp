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
#include <set>
using namespace std;
  
/*
     0  1  2
W = {1, 2, 3}
V = {6, 10, 12}
M = 5

(W,V)   M 0  1  2   3   4   5
0      [  0, 0, 0,  0,  0,  0]
1      [  0, 6, 6,  6,  6,  6]
2      [  0, 6, 12, 16, 16, 16]
3      [  0, 6, 12, 16, 18, 22]
*/

int knapsackDynamic(int W, vector<int> weights, vector<int> values) {
    int cache[weights.size() + 1][W + 1];
    
    for (int i = 1; i <= weights.size(); ++i) {
        for (int j = 1; j <= W; ++j) {
            if (weights[i-1] > j) 
                cache[i][j] = cache[i-1][j];
            else 
                cache[i][j] = std::max(
                    cache[i-1][j],
                    cache[i-1][j - weights[i-1]] + values[i-1]);
        }
    }
    
    return cache[weights.size()][W];
}

int knapsack(int W, vector<int> weights, vector<int> values, int index) {
    if (index >= weights.size()) return 0;
    
    if (weights[index] > W)
        return knapsack(W, weights, values, index + 1);
    else
        return std::max(
            knapsack(W - weights[index], weights, values, index + 1) + values[index],
            knapsack(W, weights, values, index + 1));
}

int knapsack(int W, vector<int> weights, vector<int> values) {
    return knapsack(W, weights, values, 0);
}

int main()
{
    int maxWeight = 507;
    /*vector<int> weights = {10, 20, 30, 15, 1, 2, 8, 12, 10, 13, 100, 200, 68, 75, 2000, 3000};
    vector<int> values = {60, 100, 120, 15, 16, 21, 3, 4, 500, 700, 12, 9, 85, 74, 19, 7846};*/
    
    vector<int> weights = {1, 2, 3};
    vector<int> values = {1, 2, 3};
    
    clock_t begin_time = clock();
    int value = knapsack(maxWeight, weights, values);
    std::cout << "Normal Took " << float( clock () - begin_time ) /  CLOCKS_PER_SEC << endl;
    cout << "Normal value = " << value << endl;
    
    begin_time = clock();
    value = knapsackDynamic(maxWeight, weights, values);
    std::cout << "Dynamic Took " << float( clock () - begin_time ) /  CLOCKS_PER_SEC << endl;
    cout << "Dynamic value = " << value << endl;

    return 0;
}
