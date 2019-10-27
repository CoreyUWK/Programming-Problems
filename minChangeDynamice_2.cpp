/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h> 

using namespace std;

int curreny[] = {1, 5, 6, 9};
int currenyAmount = sizeof(curreny) / sizeof(curreny[0]);

// O(n + 1 + m + n) = O(n)
int minChange(int amount)
{
    int tableSize = amount + 1;
    int table[tableSize];
    
    table[0] = 0;
    for (int i = 1; i < tableSize; ++i)
    {
        table[i] = INT_MAX;
    }
  
    // Iterate over table to set min change per index
    for (int i = 1; i < tableSize; ++i)
    {
        // Loop over curreny amounts to get minChange
        for (int j = 0; j < currenyAmount; ++j)
        {
            int lastMin = i - curreny[j];
            if (lastMin >= 0)
            {
                int newMin = 1 + table[lastMin];
                
#ifdef Debug
                printf("i[%d] curreny[%d] lastMin[%d] newMin[%d]\n", 
                    i, curreny[j], lastMin, newMin);
#endif
                if (table[i] > newMin)
                {
                    table[i] = newMin;
                }
            }
            else
            {
                break;
            }
        }
    }
    
#ifdef Debug
    // Print Table
    for (int i = 0; i <tableSize; ++i)
    {
        cout << table[i] << ", ";
    }
#endif
    cout << endl;
    
    return table[amount];
}

int main()
{
    cout<<minChange(11);

    return 0;
}
