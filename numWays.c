// Given an integer n, return the number of ways it can be represented as a sum of 1s and 2s, order matters.

#include <iostream>
using namespace std;

int numWays(int num)
{
    if (num <= 0)
        return 0;
    else if (num == 1)
        return 1;
    else if (num == 2)
        return 2;
    
    return numWays(num - 1) + numWays(num - 2);
}

int main()
{
    cout << "Ways: " << numWays(5) << std::endl;
    return 0;
}
