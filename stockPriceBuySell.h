/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <array>
#include <vector>
using namespace std;

struct BuySellPair {
    int buyIndex;
    int sellIndex;
};

void StockBuySell(int prices[], std::size_t pLength, std::vector<BuySellPair> &results)
{
    int priceIndex = 0;
    BuySellPair pair;
    
    if (pLength <= 1) return;

    while (priceIndex < pLength - 1) {
        // Find Local Min (that is when to start buying since will get profit)
        while (priceIndex < (pLength - 1) && 
               prices[priceIndex] >= prices[priceIndex + 1]) {
            ++priceIndex;               
       }
       
       if (priceIndex == (pLength - 1)) {
           return; // No local min found so no good day to buy
       }
       
       pair.buyIndex = priceIndex++;
       
       // Find local Max after Local min (when to sell)
       while ((priceIndex + 1) < pLength && prices[priceIndex + 1] >= prices[priceIndex]) {
           ++priceIndex;
       }
       
       pair.sellIndex = priceIndex++;
       
       results.push_back(pair);
    }
}

int main()
{
    int a[] = {8, 1, 26, 3, 40, 5, 2};
    int aLength = sizeof(a)/sizeof(int);
    std::vector<BuySellPair> results;
    
    StockBuySell(a, aLength, results);
    for (auto pair : results) {
        cout << "Buy at " << pair.buyIndex << " Sell at " << pair.sellIndex << endl;
    }
    
    return 0;
}
