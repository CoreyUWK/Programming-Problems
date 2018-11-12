/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <vector>    

using namespace std;

template <std::size_t arraySize>
string kthMostFrequent(string (&sList)[arraySize], int k)
{
    std::map<string, int> stringMap;

    // Create Hash Map string -> frequency
    for (string s : sList)
    {
        if (stringMap.end() == stringMap.find(s))
            stringMap[s] = 0;
        ++stringMap[s];
    }
    
    // Sort by moving map into vector or set
    std::vector<std::pair<string, int>> stringMapSorted;
    std::copy(stringMap.begin(), stringMap.end(), std::inserter(stringMapSorted, stringMapSorted.begin()));
    
    // https://thispointer.com/how-to-sort-a-map-by-value-in-c/
    // https://en.cppreference.com/w/cpp/utility/functional/function
    // http://www.techiedelight.com/sort-map-values-cpp/
    // http://www.cplusplus.com/reference/iterator/inserter/
    /*typedef std::function<bool(std::pair<string, int>, std::pair<string, int>)> Compare;
    Compare cmpFunction = [](std::pair<string, int> elem1, std::pair<string, int> elem2)
                        {
                            return elem1.second >= elem2.second;
                        };*/

    std::sort(stringMapSorted.begin(), stringMapSorted.end(), [](std::pair<string, int> elem1, std::pair<string, int> elem2)
                        {
                            return elem1.second >= elem2.second;
                        });
    
    // Get Kth frequency
    string kthMostFrequentStr = ""; 
    for (const auto &pair : stringMapSorted)
    {
        if (pair.second == k)
        {
            kthMostFrequentStr = pair.first;
            break;
        }
    }
    
    return kthMostFrequentStr;
}

int main()
{
    string list[] = {"a", "b", "b"};
    cout << kthMostFrequent(list, 2) << std::endl;
    return 0;
}



/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;


bool Compare (const std::pair<string, int> &lhs, const std::pair<string, int> &rhs) {
    return lhs.second > rhs.second;
}


string kthMostFrequent(std::vector<string> words, int k) {
    if (k == 0) throw "Invalid kth argument, k > 0";
    
    // 1) Hashmap of words to frequency, could also make map for frequency to vector<words>
    //  then copy to vector and sort
    // 2) vector of pairs (wors to frequency) than use make_heap
    
    std::unordered_map<string, int> map = {};
    std::vector<std::pair<string, int>> sortedList;
    
    for (string word : words) {
        ++map[word];
    }
    
    for (auto &pair : map) {
        sortedList.push_back(std::pair<string, int>(pair.first, pair.second));
    }
    std::sort(sortedList.begin(), sortedList.end(), Compare);
    
    /*for (auto pair : sortedList) {
        cout << pair.first << " " << pair.second << endl;
    }*/

    if (sortedList.size() - 1 < k) throw "No kth frequent argument, k > 0";
    return sortedList[k].first;
}

int main ()
{
    std::vector<string> words = {"Hello", "Hello", "are", "you", "there", "I", "am", "there"};
    cout << kthMostFrequent(words, 6);
    return 0;
}

