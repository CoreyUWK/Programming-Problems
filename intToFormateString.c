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

//1234
//1,234

// 104450 -> 104,450
// 123123123 -> 123,123,123

// 1000000 -> 10,00,000
// 00010100

//EN style = {3, 6, 9, 12, 15}
//IN style = {3, 5, 7, 9, 11, 13}
//map <string, vector <int> > style_map

std::unordered_map< std::string, vector<std::pair<int, int>> > _styleMap = {
    {"EN", { {3, -1} } },
    {"IN", { {3, 3}, {2, -1} } },
};

string formatNum(int num, string styleMask) {
    string result = "";
    int firstNum = 0;
    int numIndex = 0;
    int styleVectorIndex = 0;
    int styleSeperator = 0;
    
    vector<std::pair<int, int>> style = _styleMap[styleMask];
    styleSeperator = style[styleVectorIndex].first;
    
    while (0 < num)
    {
        firstNum = num % 10;
        num /= 10;
        //cout << "firstNum: " << firstNum << " Num: " << num << std::endl;
        //cout << "index: " << numIndex << " first: " << styleSeperator << " Second: " << style[styleVectorIndex].second << std::endl;

        if (numIndex != 0 && 0 == numIndex % styleSeperator)
        {
            result += ",";
            if (-1 != style[styleVectorIndex].second && 
                numIndex >= style[styleVectorIndex].second)
            {
                styleSeperator += style[++styleVectorIndex].first;
            }
        }
        result += std::to_string(firstNum);
        ++numIndex;
    }
    reverse(result.begin(), result.end());
    
    return result;
}

int main() {
	string res;
	int _num = 1234567;
	
	// cin >> _num;
	res = formatNum(_num, "IN");
	cout << res << std::endl;
	
	return 0;
}
