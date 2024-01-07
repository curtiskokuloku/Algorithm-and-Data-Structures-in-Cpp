#include <iostream>
using namespace std;

class AdjacencyMatrixGraph {
    public:
        int V;              // number of vertices in the graph
        int E;              // number of edges in the graph
        int** adjMatrix;    // adjacency matrix

        // Constructor; creates a graph of n number of nodes
        AdjacencyMatrixGraph(int nodes) {
            this->V = nodes;
            this->E = 0;
            this->adjMatrix = new int*[nodes];
            initializeMatrix(this->adjMatrix, nodes);
        }

        // Add new edges (u, v) and (v, u) to the graph
        void addEdge(int u, int v) {
            if (E == V) resize(V * 2);
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1;
            E++;
        }

        // Print the elements in the adjacency matrix
        string display() {
            string s = "";
            s += to_string(V) + " vertices, " + to_string(E) + " edges\n";
            for (int v = 0; v < V; v++) {
                s += to_string(v) + ": ";
                for (int w = 0; w < V; w++) {
                    s += to_string(adjMatrix[v][w]) + " ";
                }
                s += "\n";
            }
            return s;
        }

        // Destructor is to clean up allocated memory
        ~AdjacencyMatrixGraph() {
            for (int i = 0; i < V; i++) {
                delete[] adjMatrix[i];
            }
            delete[] adjMatrix;
        }

    private:
        void initializeMatrix(int** matrix, int n) {
            for (int i = 0; i < n; i++) {
                matrix[i] = new int[n];
                for (int j = 0; j < n; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Increase the number of vertices (nodes) in the graph
        void resize(int nodes) {
            int** newMatrix = new int*[nodes];
            initializeMatrix(newMatrix, nodes);
            int minNodes = min(nodes, V);  // Determine the number of nodes to copy
            for (int i = 0; i < minNodes; i++) {
                for (int j = 0; j < minNodes; j++) {
                    newMatrix[i][j] = adjMatrix[i][j];
                }
            }
            for (int i = 0; i < V; i++) {
                delete[] adjMatrix[i];
            }
            delete[] adjMatrix;
            adjMatrix = newMatrix;
            V = nodes;
        }
};

int main() {
    AdjacencyMatrixGraph g(4);
    g.addEdge(0, 1);    // (0, 1) and (1, 0)
    g.addEdge(1, 2);    // (1, 2) and (2, 1)
    g.addEdge(2, 3);    // (2, 3) and (3, 2)
    g.addEdge(3, 0);    // (3, 0) and (0, 3)
    g.addEdge(4, 5);    // (4, 5) and (5, 4)
    g.addEdge(5, 6);    // (5, 6) and (6, 5)
    g.addEdge(6, 7);    // (6, 7) and (7, 6)
    g.addEdge(7, 0);    // (7, 0) and (0, 7)
    cout << g.display() << endl;
    return 0;
}