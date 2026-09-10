#include<iostream>
#include "matrix.h"
using namespace std;

vector<vector<int>> multiplyMatrices(
    const vector<vector<int>>& A,
    const vector<vector<int>>& B){

    int n = A.size();      // Rows of A
    int m = B[0].size();   // Columns of B
    int k = B.size();      // Rows of B

    // Vector C to store the final result n rows and m columns all initialize with 0
    vector<vector<int>> C(n, vector<int>(m, 0));
    
    // Main logic to multiply 2 Matrices 
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int x=0; x<k; x++){
                C[i][j] = C[i][j] + A[i][x] * B[x][j];
            }
        }
    }
    return C;
}