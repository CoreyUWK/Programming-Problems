/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <array>
using namespace std;


void MergeArray(int a[], size_t aLength, int b[], size_t bLength, int c[])
{
    unsigned int aPtr = 0;
    unsigned int bPtr = 0;
    int totalSize = aLength + bLength;
    
    for (int i = 0; i < totalSize; ++i)
    {
        if (bPtr == bLength || (aPtr != aLength && a[aPtr] < b[bPtr]))
        {
            c[i] = a[aPtr++];
        }
        else
        {
            c[i] = b[bPtr++];
        }
    }
}

int main()
{
    int a[] = {1,3,5,7,9};
    unsigned int aLength = sizeof(a) / sizeof(int);
    int b[] = {2,4,6};
    unsigned int bLength = sizeof(b) / sizeof(int);
    int c[aLength + bLength];
    
    MergeArray(a, aLength, b, bLength, c);
    for (int val : c)
    {
        cout << val << endl;
    }

    return 0;
}
