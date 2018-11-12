/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph {
    int V; // No. of vertices
    
    // Pointer to an array containing adjanceny lists 
    list<int> *adj;
    
    void topologicalSortUtil(int v, bool visited[], stack<int> &stack);
    
    public:
    Graph(int v); 
    
    void addEdge(int v, int w);
    
    // Prints a topological sort of the complete graph
    void topologicalSort();
};

Graph::Graph(int v) {
    this->V = v;
    adj = new list<int>[v];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // add w to v's list
}

void Graph::topologicalSortUtil(int v, bool visited[], std::stack<int> &stack) {
    // Mark current node as visited
    visited[v] = true;
    
    // Recur for all vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i) {
        if (!visited[*i])
            topologicalSortUtil(*i, visited, stack);
    }
    
    // Push current vertex to stack which stores result
    stack.push(v);
}


// Algo is a depth first search (DFS) with an extra stack => O(V + E)
void Graph::topologicalSort() {
    std::stack<int> stack;
    
    // Mark all vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; ++i) {
        visited[i] = false;
    }
    
    // Call the recursive helper function to store topologicalSort
    // starting from all vertices one by one
    for (int i = 0; i < V; ++i) {
        if (visited[i] == false) {
            topologicalSortUtil(i, visited, stack);
        }
    }
    
    while (!stack.empty()) {
        cout << stack.top() << " ";
        stack.pop();
    }
}

int main()
{
    Graph g(6);
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 
  
    cout << "Following is a Topological Sort of the given graph \n"; 
    g.topologicalSort();    
    return 0;
}
