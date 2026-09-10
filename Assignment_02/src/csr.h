#ifndef CSR_H
#define CSR_H

#include <vector> // vector library
#include <string> // string library
using namespace std;

// Template for CSR Graph for weighted undirected graph
struct CSRGraph {

    int vertices;   // Total vertices in the grpah 
    int edges;      // edges in the graph 

    vector<int> row_ptr;
    vector<int> col;
    vector<long long> weight;
};

// Fuunction declaration for CSR conversion
CSRGraph convertToCSR(const string& filename);

#endif