/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

#define binaryFloatSize (sizeof(float) * CHAR_BIT)
union FloatToInt {
    float input;
    unsigned int output;
};

bitset<binaryFloatSize> floatToBinary (float val) {
    /*FloatToInt conversion = { .input = val };
    return bitset<sizeof(float) * CHAR_BIT>(conversion.output);*/
    /*int floatVal = *((int *)&val);
    bitset<binaryFloatSize> set;
    for (int i = 0; i < binaryFloatSize; ++i) {
        set[i] = ( (1 << i) & floatVal) ? 0 : 1;
    }
    return set;*/
    
    char *bits = reinterpret_cast<char*>(&val);
    for (size_t n = 0; n < sizeof(val); ++n) {
        cout << bitset<8>(bits[n]);
    }
}

int main()
{
    /*cout << floatToBinary(1.0) << endl; 

    float f=1.0;
    cout<<bitset<sizeof f*8>(*(long unsigned int*)(&f))<<endl;*/
    
    int i; // declare variables
    float f;
    int bit = 0;
    cout << "Enter a floating point number: "; // enter a float
    cin >> f; // read in the number
    
    int *b = reinterpret_cast<int*>(&f); // use reinterpret_cast function
    for (int k = 31; k >=0; k--) // for loop to print out binary pattern
    {
        bit = ((*b >> k)&1); // get the copied bit value shift right k times, then and with a 1.
        cout << bit; // print the bit.
    }
    

    return 0;
}
