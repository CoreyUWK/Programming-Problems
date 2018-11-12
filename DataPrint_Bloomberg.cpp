/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <unordered_set>
using namespace std;

void SP(int i) {
    static int nextExpected = 1;
    static unordered_set<int> map;
    
    if (i != nextExpected) {
        map.insert(i);
    }
    else {
        cout << nextExpected << endl;
        nextExpected += 1;
        while (map.find(nextExpected) != map.end()) {
            cout << nextExpected << endl;
            map.erase(nextExpected);
            nextExpected += 1;
        }
    }
}

int main()
{
    SP(4);
    SP(2);
    SP(3);
    SP(1);
    
    SP(5);
    SP(9);
    SP(7);
    SP(6);
    SP(8);

    SP(15);
    SP(10);
    SP(14);
    SP(18);
    SP(16);
    SP(11);
    SP(13);
    SP(12);
    SP(17);
    
    
    return 0;
}
