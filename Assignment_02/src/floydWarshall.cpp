#include "floydWarshall.h"   
#include <fstream>
#include <iostream>
#include <climits>
#include <string>
using namespace std;
const long long INF = LLONG_MAX / 4;

// Read adjacency matrix
vector<vector<long long>> readMatrix(const string& filename){
    ifstream file(filename);  
    if (!file.is_open()) {
        cerr << "Error: Cannot open input file: " << filename << endl;
        return {};
    }

    int n;
    // Taking the n as dimenssions of the matrix
    file >> n;
    
    // Matrix of n*n
    vector<vector<long long>> matrix(n, vector<long long>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Taking the input of matrix as string
            string value;
            file >> value;
            if (value == "INF") {
                // INF is not a string, It is defined above
                matrix[i][j] = INF;
            }
            else {
                // stoll = string to long long conversion
                matrix[i][j] = stoll(value);
            }
        }
    }
    file.close();
    // return the final matrix
    return matrix;
}

// Floyd-Warshall Algorithm
// This algorithm is used to find the all pair shortest path
// Take the input matrix as a input
vector<vector<long long>> floydWarshall(vector<vector<long long>> matrix){
    int n = matrix.size();
    // We have to apply the algorithm by 0 to n-1 time, means n matrix will be created.
    // We are checking here, are we able to reach from i to j using k with minimum cost or not, if yes update the path, other keep it as it is. 
    for (int k = 0; k < n; k++) {
        // by using i and j we are taking value of actual matrix
        for (int i = 0; i < n; i++) {

            // It means there is no path between i and k, leave this entry
            if (matrix[i][k] == INF) {
                continue;
            }
            for (int j = 0; j < n; j++) {

                // It means there is no path between k and j 
                // so just leave this entry
                if (matrix[k][j] == INF) {
                    continue;
                }

                // ex. for i to j via k
                // If there is a path between (i, j) and (j, k) then we will find the new possible distance and update the distance if it is lesser than the current distance
                // a[i, j] = a[i, k] + a[k, j]
                // If new path is lesser than previous one, just update it 
                long long newDistance = matrix[i][k] + matrix[k][j];
                if (newDistance < matrix[i][j]) {
                    matrix[i][j] = newDistance;
                }
            }
        }
    }
    // return final output matrix
    return matrix;
}