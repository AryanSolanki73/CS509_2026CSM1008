#include<iostream>
#include "matrix.h"
using namespace std;

vector<vector<int>> multiplyMatrices(
    const vector<vector<int>>& A,
    const vector<vector<int>>& B){

    int n = A.size();
    int m = B[0].size();
    int k = B.size();

    vector<vector<int>> C(n, vector<int>(m, 0));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int x=0; x<k; x++){
                C[i][j] += A[i][x] * B[x][j];
            }
        }
    }
    return C;
}