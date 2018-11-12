/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <sstream>
using namespace std;

bool isBigEndian() {
    unsigned int u32Reg = 0x1234;
    char *u8Ptr = (char*)&u32Reg;
    
    /* BigEndian = memory moves down
       0x0A0B0C0D  =>   0D (i + 3)
                        0C (i + 2)
                        0B (i + 1)
                        0A (i)
       
        Big Endian Byte Order: The most significant byte (the "big end") of the
            data is placed at the byte with the lowest address. The rest of the data 
            is placed in order in the next three bytes in memory.
        
        Little Endian Byte Order: The least significant byte (the "little end") 
            of the data is placed at the byte with the lowest address. The rest 
            of the data is placed in order in the next three bytes in memory.
       */
    
    if (0x1 == *u8Ptr) {
        // Check if BigEndian
        return true;
    }
    // cout << *u8Ptr << endl;
    return false;
}

int main()
{
    cout << isBigEndian() << endl;
    return 0;
}
