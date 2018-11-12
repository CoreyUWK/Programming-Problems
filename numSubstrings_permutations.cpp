/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


void permutations(string prefix, string suffix, std::vector<string> &results) {
    if (suffix.empty()) {
        results.push_back(prefix);
    }
    else {
        for (int i = 0; i < suffix.length(); ++i) {
            //cout << "New prefix: " << prefix + suffix[i] << endl;
            //cout << "New suffix: " << suffix.substr(i + 1, suffix.length() - (i + 1)) << endl;
            
            permutations(prefix + suffix[i], 
                suffix.substr(0, i) + 
                suffix.substr(i + 1, suffix.length() - (i + 1)),
                results);
        }
    }
}

std::vector<string> permutations(string s) {
    std::vector<string> results;
    permutations("", s, results);
    return results;
}

int numSubStrings (string s) {
    int count = 0;
    std::unordered_set<string> map;
    
    for (int start = 0; start < s.length(); ++start) {
        // substr from i to end
        for (int end = start; end < s.length(); ++end) {
            string substr = s.substr(start, (end - start) + 1);
            if (map.end() == map.find(substr)) {
                map.insert(substr);
                ++count;
            }
        }
    }
    
    return count;
}

int main()
{
    cout << "Num Substrings " << numSubStrings("abc") << endl;
    std::vector<string> results = permutations("abc");
    for (string s : results) {
        cout << s << endl;
    }
    return 0;
}
