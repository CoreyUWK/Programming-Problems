#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <tuple>
#include <numeric>
#include <unordered_map>
#include <limits>
using namespace std;


vector<char> route(unordered_map<char, char> &trips) {
    // Output
    vector<char> path;
    
    // DFS of Graph
    queue<char> queue; 
    unordered_map<char, bool> visited;

    // Find Src Start
    unordered_map<char,int> occurance;
    
    // Setup O(Src's)
    for (auto trip : trips) {
        occurance[trip.first]++;
        occurance[trip.second]++;
        visited[trip.first] = false;
        visited[trip.second] = false;
    }
    
    // Find src start O(V)
    char src = ' ';
    for (auto o : occurance) {
        if (o.second == 1) {
            // Found Src or dest
            if (trips.find(o.first) != trips.end()) {
                // is Src
                src = o.first;   
            }
        }
    }

    if (src == ' ') {
        cout << "No Src" << endl;
        return path;
    }
    
    queue.push(src);
    visited[src] = true;
    
    // DFS Topological sort O(E + V)
    while (!queue.empty()) {
        char top = queue.front();
        queue.pop();
        
        if (!visited[trips[top]]) {
            queue.push(trips[top]);
            visited[trips[top]] = true;
        }
        
        path.push_back(top);
    }
    
    return path;    
}

int main()
{
/* C->B
   D->G
   A->C
   B->D
*/
    unordered_map<char, char> trips;
    trips['C'] = 'B';
    trips['D'] = 'G';
    trips['A'] = 'C';
    trips['B'] = 'D';
    
    vector<char> path = route(trips);
    for (char c : path) {
        cout << c << endl;    
    }
    
    return 0;
}