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
#include <string.h>

using namespace std;

void reverseString(string &strWord) {
    // reverse(strWord.begin(), strWord.end());
    int forward = 0, backword = strWord.length() - 1;
    
    while (forward < backword)
    {
        std::swap(strWord[forward++], strWord[backword--]);
    }
}

void reverseWord(char *word, int length)
{
    int forward = 0, backword = length - 1;
    char tmp;
    
    while (forward < backword)
    {
        tmp = word[forward];
        word[forward] = word[backword];
        word[backword] = tmp;
        ++forward;
        --backword;
    }
}

void reverseWords(char *sentence, int length) {
    int wordStart = 0;
    int tmpIndex = 0;
    
    reverseWord(sentence, length);

    while (tmpIndex <= length)
    {
        if (sentence[tmpIndex] == ' ' || sentence[tmpIndex] == '\0')
        {
            int len = tmpIndex - wordStart;
            sentence[tmpIndex] = '\0';
            reverseWord(&sentence[wordStart], len);
            sentence[tmpIndex] = ' ';
            wordStart = tmpIndex + 1;
        }
        
        ++tmpIndex;
    }
}

int main() {
    char *str = (char *)calloc(255, sizeof(char));
    strcpy(str, "Hello World Me Fine");

    cout << "Originl: " << str << std::endl;
    reverseWords(str, 19);
	cout << "Reverse: " << str << std::endl;
	
	return 0;
}
