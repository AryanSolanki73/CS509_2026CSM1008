#include "csr.h"    // csr.h file included
#include <fstream>  // file input output
#include <iostream> // I/O library
#include <utility> 
using namespace std;

// To convert Adjacency list --> CSR
// Convert in row_ptr, col, weight Arrays
// Taking input file as argument here
CSRGraph convertToCSR(const string& filename) {

    // open file with name 'file'
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Cannot open input file: " << filename << endl;
        return {};
    }

    int V, E;
    // ">>" : This operator in c++ remove the spaces, newline, tabs
    // Read Vertice and Edges from first line
    file >> V >> E;

    CSRGraph graph;  // CSRGraph object (template made in csr.h file)

    graph.vertices = V;
    graph.edges = 0;

    // Temporary adjacency list
    // Pair take (vertex, weight);
    // V is total number of vertices
    vector<vector<pair<int, long long>>> adjacency(V);

    // Read adjacency list
    for (int i = 0; i < V; i++) {
        int u;       // Vertex 
        int degree;  // Connection with other vertices 

        // Taking vertex and degree of that vertex from file
        file >> u >> degree; 
        
        // Another loop to extract {vertex, weight} Pair
        for (int j = 0; j < degree; j++) {
            int neighbour;
            long long weight;

            file >> neighbour >> weight;
            adjacency[u].push_back({neighbour, weight});
            // To make it undirected graph use below line
            adjacency[neighbour].push_back({u, weight});
        }
    }

    int totalEntries = 0;
    for (int u = 0; u < V; u++)
    {
        totalEntries += adjacency[u].size();
    }
    graph.edges = totalEntries;

    // Construct row_ptr
    graph.row_ptr.resize(V + 1);  // fixing size of row_ptr vector
    graph.row_ptr[0] = 0;         // row_ptr[0] = 0, always
    for (int u = 0; u < V; u++) {
        graph.row_ptr[u + 1] = graph.row_ptr[u] + adjacency[u].size();
    }

    // Construct col and weight
    graph.col.resize(totalEntries);
    graph.weight.resize(totalEntries);

    int index = 0;
    // To iterating over vector<vector<Pair<int, int>>>
    for (int u = 0; u < V; u++) {
        for (auto edge : adjacency[u]) {
            graph.col[index] = edge.first;      // Pair ka first part
            graph.weight[index] = edge.second;  // Pair ka second part
            index++;
        }
    }

    // closing the file
    file.close();
    return graph;
}