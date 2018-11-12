#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

void reverseString(string &strVal) {
    // reverse(strVal.begin(), strVal.end());
    int forward = 0, backword = strVal.length() - 1;
    
    while (forward < backword)
    {
        std::swap(strVal[forward++], strVal[backword--]);
    }
}

int main() {
    string str = "Hello World";
    reverseString(str);
	cout << str;
	
	return 0;
}
