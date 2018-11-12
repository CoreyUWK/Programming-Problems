/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <vector>  
#include <queue>
#include <stack>
using namespace std;

template <std::size_t rows, std::size_t cols>
bool MatrixFind(int (&a)[rows][cols], int target)
{
    if (rows == 0 || cols == 0) return false;

    int searchRow = 0;
    int searchCol = cols - 1;
    while ( searchRow < rows && searchCol >= 0)
	{
        int val = a[searchRow][searchCol];
        cout << "Val: " << val << endl;
        if (val == target)
            return true;
        else if (target < val) 
            --searchCol;
        else 
            ++searchRow;
    }
    
    return false;
}


int main()
{
    unsigned int m = 4;
    unsigned int n = 4;
    int a[4][4] = { {0, 1, 2, 3},
                    {4, 5, 6, 7},
                    {8, 9, 10, 11},
                    {12, 13, 14, 15} };
                    
    bool result = MatrixFind(a, 8);
    cout << result;
    return 0;
}
