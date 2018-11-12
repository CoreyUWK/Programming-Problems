/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


int minChange(int amount, const std::array<int, 3> & currency, int *cache) {
    if (amount == 0) return 0;
   
    int min = amount; // Not this could be an issue if currency does not have 1 value
    for (int change : currency) {
        if (change > amount) continue;

        int newAmount = amount - change;
        if (cache[amount] == -1) {
            int tmpChange = 1 + minChange(newAmount, currency, cache);
            cache[amount] = tmpChange;
        }

        if (min > cache[amount]) {
            min = cache[amount];
        }
    }

    return min;
}

int minChange(int amount, const std::array<int, 3> &currency) {
    int cache[amount + 1];
    
    cache[0] = 0;
    for (int i = 1; i <= amount; ++i) {
        cache[i] = -1;
    }
    
    return minChange(amount, currency, cache);
}

int main() {
    std::array<int, 3> currency ( {4,3,1} );
    cout << minChange(25, currency);
    return 0;
}
