/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

/* 6 
 4, 3, 1

6 
min 6 

x   coin   new_x
6 - 4    = 2
2 - 1    = 1
1 - 1    = 0 */

template <std::size_t array_size>
int Change(int x, int (&coins) [array_size])
{
    if (0 == x)
        return 0;
    
    int minChange = x;
    for (int coin : coins)
    {
        if (coin > x) 
            continue;
        
        int change = Change(x - coin, coins);
        if (minChange > change + 1)
            minChange = change + 1;
    }
    
    return minChange;
}

int main()
{
    int coins[] = {4, 3, 1};
    int x = 37;
    
    cout << "Min Change of " << x << " is " << Change(x, coins);
    return 0;
}
