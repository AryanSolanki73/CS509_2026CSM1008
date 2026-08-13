#include <iostream>  // Basic input output
#include <fstream>   // For file handling 
#include <climits>   // C limits for INT_MAX or INT_MIN
#include <string>    // For string in text files
#include<chrono>     // Time Library

// .h file contains the function we have to perform
#include "../Assignment_02/src/csr.h"   
#include "../src/bellmanFord.h"
#include "../src/floydWarshall.h"

using namespace std;
using namespace chrono;  // For execution time calculation 
const long long INF = LLONG_MAX / 4;

// Command line Arguments
// argc = count of arguments
// argv = actual arguments
// argv[0] --> executable name (program (linux), program.exe(Windows))
int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Usage:\n";
        cerr << "Prims Algorithm :\n";
        cerr << "program Prims " << "<input.txt> <output.txt>\n\n";

        cerr << "Kruskal Algorithm :\n";
        cerr << "program Kruskal " << "<input.txt> <output.txt>\n";
        return 1;
    }

    // First command line input is algorithm name
    string algorithm = argv[1];
    // Second - input file
    string inputFile = argv[2];
    // Third - output file
    string outputFile = argv[3];

    // Open output file where to write the ans
    ofstream out(outputFile);
    if (!out.is_open()) {
        // If file is not opening
        cerr << "Error: Cannot open output file: " << outputFile << endl;
        return 1;
    }

    // Bellman Ford Algorithm
    // String comparision with key "bellman"
    if (algorithm == "prims") {

        // Convert adjacency list -> CSR
        // Using object of CSRGraph
        CSRGraph graph = convertToCSR(inputFile);
        
        // After conversion graph vertices can't be 0
        if (graph.vertices == 0) {
            out << "Error reading graph.\n";
            out.close();
            return 1;
        }

        // Read SOURCE from input file
        // Name of that input file which we are reading is "file" now.
        ifstream file(inputFile);

        // If not able to open file
        if (!file.is_open()) {
            out << "Error opening input file.\n";
            out.close();
            return 1;
        }

        // Reading vertices and edges from input file
        int V, E;
        file >> V >> E;

        // Skip the V adjacency-list lines
        for (int i = 0; i < V; i++) {
            int u;
            int degree;

            file >> u >> degree;
            for (int j = 0; j < degree; j++) {
                int neighbour;
                long long weight;
                file >> neighbour >> weight;
            }
        }
    }
    // Kruskal Algorithm
    // argv[1] input is "kruskal"
    else if (algorithm == "kruskal") {

    }

    // Invalid Algorithm
    else {
        out << "Invalid algorithm." << endl;
        out.close();
        return 1;
    }
    out.close();
    return 0;
}