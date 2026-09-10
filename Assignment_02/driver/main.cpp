#include <iostream>  // Basic input output
#include <fstream>   // For file handling 
#include <climits>   // C limits for INT_MAX or INT_MIN
#include <string>    // For string in text files
#include<chrono>     // Time Library

// .h file contains the function we have to perform
#include "../src/csr.h"   
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
        cerr << "Bellman-Ford:\n";
        cerr << "program bellman " << "<input.txt> <output.txt>\n\n";

        cerr << "Floyd-Warshall:\n";
        cerr << "program floyd " << "<input.txt> <output.txt>\n";
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
    if (algorithm == "bellman") {

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

        // Read:
        // Last line of input file is looking like that : SOURCE(sourceWord) 0
        string sourceWord;
        int source;

        file >> sourceWord >> source;
        file.close();

        // Run Bellman-Ford
        // bool to check cycle with nrgative edge in the graph
        bool negativeCycle = false;

        //  Actual Algorithm call with timer
        auto start = high_resolution_clock::now();
        vector<long long> distance = bellmanFord(graph, source, negativeCycle);
        auto stop = high_resolution_clock::now();
        double timeTaken = duration<double, milli>(stop - start).count();

        // Write result to output file
        // Output file is opened earlier with name "out"
        // First line of output file is execution time of algorithm
        out << "Execution Time : "<< timeTaken <<" ms\n";

        if (negativeCycle) {
            out << "Negative-weight cycle reachable from source." << endl;
        }
        else if (distance.empty()) {
            out << "Invalid source vertex."
                << endl;
        }
        else {
            out << "Bellman-Ford Shortest Path Distances" << endl;
            out << "Source: " << source << endl;
            out << endl;

            // Print in file INF or distance as per distance
            for (int i = 0; i<graph.vertices; i++) {
                out << source << " -> " << i << " : ";
                if (distance[i] == INF) {
                    out << "INF";
                }
                else {
                    out << distance[i];
                }
                out << endl;
            }
        }
    }

    // Floyd-Warshall Algorithm
    // argv[1] input is "floyd"
    else if (algorithm == "floyd") {

        // Read and 2D matrix where integer are long long type
        vector<vector<long long>> matrix = readMatrix(inputFile);
        // if no matrix is their
        if (matrix.empty()) {
            out << "Error reading matrix." << endl;
            out.close();
            return 1;
        }

        // Run Floyd-Warshall with start and stop timer
        auto start = high_resolution_clock::now();
        vector<vector<long long>> result = floydWarshall(matrix);
        auto stop = high_resolution_clock::now();
        double timeTaken = duration<double, milli>(stop - start).count();

        // Write matrix to output file
        out<<"Execution Time : "<< timeTaken <<" ms\n";
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                if (result[i][j] == INF) {
                    out << "INF";
                }
                else {
                    out << result[i][j];
                }
                if (j+1 < result[i].size()) {
                    out << " ";
                }
            }
            out << endl;
        }
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