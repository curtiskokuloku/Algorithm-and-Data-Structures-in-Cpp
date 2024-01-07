#include <iostream>
#include <list>
#include <queue>
#include <stack>
using namespace std;

class AdjacencyListGraph {
    public:
        int V;              // number of vertices in the graph
        int E;              // number of edges in the graph
        list<int>* adj;     // adjacency list using list from c++ library

        // Constructor; creates a graph of n number of nodes
        AdjacencyListGraph(int nodes) {
            this->V = nodes;
            this->E = 0;
            this->adj = new list<int>[nodes];
        }

        // Add new edges (u, v) and (v, u) to the graph
        void addEdge(int u, int v) {
            if (E == V) resize(V * 2);
            adj[u].push_back(v);
            adj[v].push_back(u);
            E++;
        }

        // Breadth-First Search traversal algorithm of a graph; takes a vertex 's' as the source
        void bfs(int s) {
            bool* visited = new bool[V]; // Determine the vertices to explore
            for (int i = 0; i < V; i++) {
                visited[i] = false;
            }
            queue<int> q;
            visited[s] = true;
            q.push(s);
            int i = 0;
            string result = "";

            while (!q.empty()) {
                int u = q.front();   // get source vertex
                q.pop();
                result += (i++ < V-1) ? (to_string(u) + " --> ") : to_string(u);
                for (int v : adj[u]) {  // visit neighboring vertices
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
            cout << "BFS Traversal: " << result << endl;
            delete[] visited;
        }

        // Iterative Depth-First Search traversal algorithm of a graph; takes a vertex 's' as the source
        void dfsI(int s) {
            bool* visited = new bool[V];
            for (int i = 0; i < V; i++) {
                visited[i] = false;
            }
            stack<int> stack;
            stack.push(s);
            int i = 0;
            string result = "";

            while (!stack.empty()) {
                int u = stack.top();
                stack.pop();
                if (!visited[u]) {
                    visited[u] = true;
                    result += (i++ < V-1) ? (to_string(u) + " --> ") : to_string(u);
                    for (int v : adj[u]) {
                        if (!visited[v]) {
                            stack.push(v);
                        }
                    }
                }
            }
            cout << "Iterative DFS Traversal: " << result << endl;
            delete[] visited;
        }

        // Recursive Depth-First Search traversal algorithm of a graph; takes a vertex 's' as the source
        void dfsR(int s) {
            bool* visited = new bool[V];
            for (int i = 0; i < V; i++) {
                visited[i] = false;
            }
            int i = 0;
            string result = "Recursive DFS Traversal: ";
            dfsRHelper(s, visited, i, result);
            cout << result << endl;
            delete[] visited;
        }

        // Print the elements in the adjacency list
        string display() {
            string s = "";
            s += to_string(V) + " vertices, " + to_string(E) + " edges\n";
            for (int v = 0; v < V; v++) {
                s += to_string(v) + ": ";
                for (int w : adj[v]) {
                    s += to_string(w) + " ";
                }
                s += "\n";
            }
            return s;
        }

        // Destructor
        ~AdjacencyListGraph() {
            delete[] adj; // Deallocate the memory for the adjacency list
        }

    
    private:
        // Increase the number of vertices (nodes) in the graph IF NECESSARY
        void resize(int nodes) {
            list<int>* newAdj = new list<int>[nodes];
            for (int v = 0; v < V; v++) {
                newAdj[v] = adj[v];
            }
            delete[] adj; // Deallocate memory of the old adjacency list
            adj = newAdj;
            V = nodes;
        }

        // Helper function to perform DFS traversal recursively from a given source vertex
        void dfsRHelper(int u, bool* visited, int& i, string& result) {
            visited[u] = true;
            result += to_string(u);
            if (visitedCount(visited) < V) result += " --> ";
            for (int v : adj[u]) {
                if (!visited[v]) dfsRHelper(v, visited, i, result);
            }
        }

        // Helper function to count the number of visited vertices
        int visitedCount(bool* visited) {
            int count = 0;
            for (int v = 0; v < V; v++) {
                if (visited[v]) count++;
            }
            return count;
        }
};

int main() {
    // Create a graph with 8 vertices
    AdjacencyListGraph g(8);

    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(7, 0);

    // Display the graph's adjacency list
    cout << "Graph Adjacency List:\n" << g.display() << endl;

    // Perform BFS traversal starting from vertex 0
    g.bfs(0);

    // Perform iterative DFS traversal starting from vertex 0
    g.dfsI(0);

    // Perform recursive DFS traversal starting from vertex 0
    g.dfsR(0);

    return 0;
}
