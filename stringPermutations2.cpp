/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

void permutation(string prefix, string suffix, std::vector<string> &results)
{
    if (suffix.empty())
    {
        results.push_back(prefix);           
    }
    else
    {
        for (int i = 0; i < suffix.length(); ++i)
        {
            permutation(prefix + suffix[i], suffix.substr(0, i) + suffix.substr(i + 1, suffix.length() - (i + 1)), results);
        }
    }
}

std::vector<string> permutation(string s)
{
    std::vector<string> results;
    permutation("", s, results);
    return results;
}

int main()
{
    std::vector<string> results = permutation("abc");
    
    cout << "permutations:" << endl;
    for (string s : results){
        cout << s << endl;
    }
    return 0;
}
