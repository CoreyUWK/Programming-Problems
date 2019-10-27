/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;

/** Questions:
- Class object where creation of search data structure is of O(?)
                where function call for search is of O(1) or O(?)

- Or just create a function that takes in the list of strings and does everything, 
will be O(?) on every call, no memory cache */

/*
1) Hash map and search = O(n)
2) Hash map and sort or partial sort, then search in O(1) like array = O(n + nlogn) = O(nlogn) or O(nlogk)
3) Binary Tree (pointers, left, right more memory and more cache lines) / Hash Tree using count as hash/node index = O(log n) 
search but creation could be more (need to look into)
4) Max Heap of K - O(n) hash map + O(nlogk) 
*/
string kthMostFreqSort(vector<string> &words, int k)
{
    unordered_map<string, int> map;
    std::vector<pair<string, int>> list;
    
    // O(n)
    for (string s : words) 
    {
        ++map[s];
    }
    
    // Create Vector for sorting O(n)
    for (auto elem : map)
    {
        list.push_back(elem);
    }
    
    // Paritial Sort O(nlogk)
    partial_sort (list.begin(), list.begin() + k, list.end(), [](const pair<string, int> &left, const pair<string, int> &right){
        if (left.second > right.second)
            return true;
        return false;
    });
    
    #ifdef DEBUG_PRINT
    for (auto elem : list)
    {
        cout << elem.first << " " << elem.second << endl;
    }    
    #endif

    return list[k - 1].first;
}


string kthMostFreqHeap(vector<string> &words, int k)
{
    unordered_map<string, int> map;
    std::vector<pair<string, int>> list;
    
    // O(n)
    for (string s : words) 
    {
        ++map[s];
    }
    
    // Create Vector for sorting O(n)
    for (auto elem : map)
    {
        list.push_back(elem);
    }

    // Create Heap O(nlogn)
     auto comp = [](const pair<string, int> &left, const pair<string, int> &right){
        if (left.second <= right.second)
            return true;
        return false;
    };
    priority_queue<pair<string, int>, vector<pair<string,int>>, decltype(comp)> heap (comp, list);
    
    for (int i = 0; i < k - 1; ++i)
    {
        #ifdef DEBUG_PRINT
        cout << "here " << heap.top().first << endl;
        #endif
        heap.pop();
    }
    
    return heap.top().first;
}


int main()
{
    vector<string> words = {"a", "b", "c", "a", "a", "d", "c", "e", "f", "f", "f", "c", "f"};
    cout << kthMostFreqSort(words, 2) << endl;
    cout << kthMostFreqHeap(words, 2) << endl;
    return 0;
}
