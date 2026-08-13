#include "floydWarshall.h"   
#include <fstream>
#include <iostream>
#include <climits>
#include <string>
using namespace std;
const long long INF = LLONG_MAX / 4;

// Read adjacency matrix
vector<vector<long long>> readMatrix(const string& filename){
    ifstream file(filename);   // 
    if (!file.is_open()) {
        cerr << "Error: Cannot open input file: " << filename << endl;
        return {};
    }

    int n;
    file >> n;
    vector<vector<long long>> matrix(n, vector<long long>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            string value;
            file >> value;
            if (value == "INF") {
                matrix[i][j] = INF;
            }
            else {
                matrix[i][j] =
                    stoll(value);
            }
        }
    }
    file.close();
    return matrix;
}

// Floyd-Warshall Algorithm
vector<vector<long long>> floydWarshall(vector<vector<long long>> matrix){
    int n = matrix.size();
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (matrix[i][k] == INF) {
                continue;
            }
            for (int j = 0; j < n; j++) {
                if (matrix[k][j] == INF) {
                    continue;
                }
                long long newDistance = matrix[i][k] + matrix[k][j];
                if (newDistance < matrix[i][j]) {
                    matrix[i][j] = newDistance;
                }
            }
        }
    }
    return matrix;
}