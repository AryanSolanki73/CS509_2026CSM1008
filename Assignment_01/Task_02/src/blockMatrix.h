#ifndef BLOCK_MATRIX_MULTIPLICATION
#define BLOCK_MATRIX_MULTIPLICATION
#include<vector>
using namespace std;

vector<vector<int>> blockMatrixMultiply(
    const vector<vector<int>>& A,
    const vector<vector<int>>& B,
    int blockSize
);

#endif