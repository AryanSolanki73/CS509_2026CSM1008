#include<bits/stdc++.h>
#include <iostream>  // Basic cin, cout
#include <fstream>   // file input output
#include <string>    // Stirng operations
#include <vector>    // vector
#include <chrono>    // Timing information

#include "../../Assignment_02/src/csr.h"    // csr.h for csr conversion
#include "../src/prims.h"            // prims.h
#include "../src/kruskal.h"          // kruskal.h

using namespace std;
using namespace chrono;

// Write MST output into the output file
void writeMSTOutput(ofstream& out, const string& algorithmName, const vector<MSTEdge>& mst, long long totalWeight, double executionTime) {
    out << "Algorithm: " << algorithmName << "\n";
    out << "MST edges:\n";

    for (const MSTEdge& edge : mst) {
        out << edge.u << " " << edge.v << " " << edge.weight << "\n";
    }

    out << "Total MST weight: " << totalWeight << "\n";
    out << "Execution time: " << executionTime << " ms\n";
}


// Main
int main(int argc, char* argv[]) {

    // Command-line arguments
    if (argc != 4) {
        cerr << "Usage:\n";
        cerr << "Prim's:\n";
        cerr << "program prims " << "<input.txt> <output.txt>\n\n";

        cerr << "Kruskal's:\n";
        cerr << "program kruskal " << "<input.txt> <output.txt>\n";
        return 1;
    }

    // Read arguments

    // First argument algorithm name
    string algorithm = argv[1];
    // Second input file
    string inputFile = argv[2];
    // Third output file
    string outputFile = argv[3];

    // Open output file
    ofstream out(outputFile);
    if (!out.is_open()) {
        cerr << "Error: Cannot open output file: " << outputFile << endl;
        return 1;
    }

    // Convert input adjacency list -> CSR
    CSRGraph graph = convertToCSR(inputFile);
    if (graph.vertices == 0) {
        out << "Error reading graph.\n";
        out.close();
        return 1;
    }

    // Prim's algorithm
    if (algorithm == "prims") {
        long long totalWeight = 0;
        int startVertex = 0;

        auto start = high_resolution_clock::now();
        vector<MSTEdge> mst = primMST(graph, startVertex, totalWeight);
        auto end = high_resolution_clock::now();

        double executionTime = duration<double, milli>(end - start).count();

        // Disconnected graph
        if (mst.empty() && graph.vertices > 1) {
            out << "Error: Graph is disconnected.\n";
            out.close();
            return 1;
        }
        writeMSTOutput(out, "Prim's MST", mst, totalWeight, executionTime);
    }

    // Kruskal's algorithm
    else if (algorithm == "kruskal") {
        long long totalWeight = 0;

        auto start = high_resolution_clock::now();
        vector<MSTEdge> mst = kruskalMST(graph, totalWeight);
        auto end = high_resolution_clock::now();

        double executionTime = duration<double, milli>(end - start).count();

        // Disconnected graph
        if (mst.empty() && graph.vertices > 1) {
            out << "Error: Graph is disconnected.\n";
            out.close();
            return 1;
        }
        writeMSTOutput(out,"Kruskal's MST", mst, totalWeight, executionTime);
    }

    // Invalid algorithm
    else {
        out << "Invalid algorithm.\n";
        out.close();
        return 1;
    }
    out.close();
    return 0;
}