#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <tuple>
#include <numeric>
#include <unordered_map>

using namespace std;

class Graph {
    int V; // Number of vertices
    vector<int> *adj; // Pointer to an array containing adjaceny list
    
    public:
    Graph(int V);
    void addEdge(int v, int w);
    bool isReachable(int s, int d);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new vector<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

// A BFS function to check whether d is reachable from s
bool Graph::isReachable(int s, int d) {
    if (s == d) return true;
    
    // Mark all vertices at not visited 
    bool visited[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }
    
    // Create a queue for BFS
    queue<int> q;
    
    // Mark current node as visited and enqueue it
    visited[s] = true;
    q.push(s);
    
    while (!q.empty())
    {
        // Dequeue a vertex from queue and print it
        s = q.front();
        q.pop();
        
        // Get all adjanct vertices of the dequeued vertex s 
        // if a adjacent has not been visited, then mark it visited and enqueue
        for (int v : adj[s]) {
            // if this adjacent node is the destination node, then return true
            if (v == d) return true;
            
            // else continue to do BFS
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    
    return false;
}

int main()
{
    Graph g(5);
    g.addEdge(2, 1);
    g.addEdge(3, 4);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    
    cout << g.isReachable(0,5);

    
    return 0;
}