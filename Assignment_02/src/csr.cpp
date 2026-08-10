#include "csr.h"

#include <fstream>
#include <iostream>
#include <utility>
using namespace std;

// To convert Adjacency list --> CSR
// Convert in row_ptr, col, weight Arrays
CSRGraph convertToCSR(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Cannot open input file: " << filename << endl;
        return {};
    }

    int V, E;
    file >> V >> E;  // Read Vertice and Edges from first line

    CSRGraph graph;  // CSRGraph object

    graph.vertices = V;
    graph.edges = E;

    // Temporary adjacency list
    // Pair take (vertex, weight);
    vector<vector<pair<int, long long>>> adjacency(V);

    // Read adjacency list
    for (int i = 0; i < V; i++) {
        int u;       // Vertices 
        int degree;  // Connection with other vertices 

        file >> u >> degree;
        for (int j = 0; j < degree; j++) {
            int neighbour;
            long long weight;

            file >> neighbour >> weight;
            adjacency[u].push_back({neighbour, weight});
        }
    }

    // Construct row_ptr
    graph.row_ptr.resize(V + 1);
    graph.row_ptr[0] = 0;
    for (int u = 0; u < V; u++) {
        graph.row_ptr[u + 1] =
            graph.row_ptr[u] +
            adjacency[u].size();
    }

    // Construct col and weight
    graph.col.resize(E);
    graph.weight.resize(E);

    int index = 0;
    for (int u = 0; u < V; u++) {
        for (auto edge : adjacency[u]) {
            graph.col[index] = edge.first;
            graph.weight[index] = edge.second;
            index++;
        }
    }

    file.close();
    return graph;
}