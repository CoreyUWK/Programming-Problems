/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <algorithm>    // std::reverse
using namespace std;

n = 5
f(4) + f(3) = 3 + 2 = 5

f(4) -> f(3) + f(2) = 3
f(3) -> f(2) + f(1) = 2
f(2) -> f(1) + f(0) = 1

int fib(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    cout << fib(5);
    return 0;
}
