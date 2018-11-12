/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <array>
using namespace std;

// Returns count of possible paths to reach cell at row number m and column
// number n from the topmost leftmost cell (cell at 1, 1)
int  numberOfPaths(unsigned int m, unsigned int n)
{
    if (m == 0 || n == 0) return -1;
    else if (m == 1 && n == 1) return 0;
    else if (m == 1 || n == 1) return 1;
    
    return numberOfPaths(m - 1, n) + numberOfPaths(m, n - 1);
}

int main()
{
    int a[] = {10, 3, 7, 9, 0, 15};
    cout << numberOfPaths(1, 1);

    return 0;
}
