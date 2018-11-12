/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <array>
#include <stack>
using namespace std;

void Rotate(unsigned int *val, int n) {
    for (int i = 0; i < n; ++i)
    {
        unsigned int firstBit = *val & 0x1;
        *val >>= 1;
        *val |= (firstBit << ((sizeof(unsigned int) * 8) - 1) );
    }
}

int main()
{
    unsigned int val = 0xFFFF0001;
    Rotate(&val, 16);
    cout << std::hex << val;
    return 0;
}
