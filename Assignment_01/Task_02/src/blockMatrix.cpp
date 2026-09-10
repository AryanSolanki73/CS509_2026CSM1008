#include "blockMatrix.h"
#include <algorithm>

using namespace std;

// Performs matrix multiplication using blocking
vector<vector<int>> blockMatrixMultiply(
    const vector<vector<int>>& A,
    const vector<vector<int>>& B,
    int blockSize)
{
    // n = number of rows in A
    int n = A.size();

    // m = number of columns in A
    // Also the number of rows in B
    int m = A[0].size();

    // k = number of columns in B
    int k = B[0].size();

    // Result matrix C will be n x k
    vector<vector<int>> C(n, vector<int>(k, 0));


    // Divide the matrices into blocks
    for (int a = 0; a < n; a += blockSize) {

        for (int b = 0; b < k; b += blockSize) {

            for (int c = 0; c < m; c += blockSize) {

                // Calculate the ending index of each block
                // min() handles blocks at the matrix boundary
                int aEnd = min(a + blockSize, n);
                int bEnd = min(b + blockSize, k);
                int cEnd = min(c + blockSize, m);


                // Multiply elements inside the current blocks
                for (int i = a; i < aEnd; i++) {

                    for (int j = b; j < bEnd; j++) {

                        for (int x = c; x < cEnd; x++) {

                            // Add A[i][x] * B[x][j] to C[i][j]
                            C[i][j] += A[i][x] * B[x][j];
                        }
                    }
                }
            }
        }
    }

    return C;
}