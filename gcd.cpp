// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
#include <numeric>
#include <iostream> 
#include <algorithm>

// Finds the GCD for first set of numbers, then uses the result to find gcd with next number
int generalizedGCD(int num, int* arr)
{
    // WRITE YOUR CODE HERE
    int gcdOut = __gcd(arr[0], (num > 1) ? arr[1] : 1);
    for (int i = 2; i < num; ++i) {
        gcdOut = __gcd(gcdOut, arr[i]);
    }
    
    return gcdOut;
}

// Euclid algorithm
int gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}
// FUNCTION SIGNATURE ENDS