/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <chrono>
using namespace std;

int makeChangeCount4(const std::vector<int> &curreny, int change, int i) {
    if (change < 0) return 0;
    if (change == 0) return 1;
    if (i < 0) return 0;
    
    int countInclude = makeChangeCount(curreny, change - curreny[i], i);
    int countExclude = makeChangeCount(curreny, change, i - 1);
    return countInclude + countExclude;
}

int makeChangeCount4(const std::vector<int> &curreny, int change) {
    if (change == 0) return 1;
    if (curreny.size() == 0) return 0;
    
    return makeChangeCount(curreny, change, curreny.size() - 1);
}

int makeChangeCount(const std::vector<int> &coins, int x, int max)
{
    if (x <= 0) {
        return 1;
    }
    
    int countInclude = 0;
    for (int i = 0; i < coins.size(); ++i) {
        if (x >= coins[i] && max >= coins[i]) {
            countInclude += makeChangeCount(coins, x - coins[i], coins[i]);
        }
        else {
            break;
        }
    }
    
    return countInclude;
}

int makeChangeCount2(const std::vector<int> &coins, int x, int i) {
    if (x == 0) return 1;
    if (x < 0 || i < 0) return 0;
    
    return makeChangeCount2(coins, x - coins[i], i) + makeChangeCount2(coins, x, i - 1);
}

int makeChangeCount3(const std::vector<int> &coins, int x) {
    int cache[x + 1] = {};
    cache[0] = 1; // So addition works
    
    // Only if order not known and not const
    // std::sort(coins.begin(), coins.end());
    
    for (int coin : coins) {
        for (int cacheIdx = coin; cacheIdx <= x; ++cacheIdx) {
            cache[cacheIdx] += cache[cacheIdx - coin];
        }
    }
    return cache[x];
}

int main()
{
    int amount = 1000;
    std::vector<int> coins{1,5,10,20,50,100};
    
    auto start = std::chrono::high_resolution_clock::now();
    cout << makeChangeCount(coins, amount, coins[coins.size() - 1]) << endl;
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Elapsed time: " << elapsed.count() << " s\n";

    start = std::chrono::high_resolution_clock::now();
    cout << makeChangeCount2(coins, amount, coins.size() - 1) << endl;
    finish = std::chrono::high_resolution_clock::now();
    elapsed = finish - start;
    std::cout << "Elapsed time: " << elapsed.count() << " s\n";

    start = std::chrono::high_resolution_clock::now();
    cout << makeChangeCount3(coins, amount) << endl;
    finish = std::chrono::high_resolution_clock::now();
    elapsed = finish - start;
    std::cout << "Elapsed time: " << elapsed.count() << " s\n";

    return 0;
}
