#include "blockMatrix.h"
#include<algorithm>
using namespace std;

vector<vector<int>> blockMatrixMultiply(
    const vector<vector<int>>& A,
    const vector<vector<int>>& B,
    int blockSize)
{
    int n = A.size();
    int m = A[0].size();
    int k = B[0].size();

    vector<vector<int>> C(n, vector<int>(m, 0));
    for(int a=0; a<n; a+=blockSize){
        for(int b=0; b<m; b+=blockSize){
            for(int c=0; c<k; c+=blockSize){
                int aEnd = min(a+blockSize, n);
                int bEnd = min(b+blockSize, m);
                int cEnd = min(c+blockSize, k);

                for(int i=a; i<aEnd; i++){
                    for(int j=b; j<bEnd; j++){
                        for(int x=c; x<cEnd; x++){
                            C[i][j] += A[i][x] * B[x][j];
                        }
                    }
                }
            }
        }
    }
    return C;
}