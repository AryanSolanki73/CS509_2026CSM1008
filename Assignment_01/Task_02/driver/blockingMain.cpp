#include<iostream>
#include<fstream>
#include<chrono>
#include<vector>
#include"../src/blockMatrix.h"
using namespace std;
using namespace chrono;

int main(int argc, char* argv[]){
    if(argc != 3){
        cout<<"Use : blockMatrix Inputfile Outputfile";
        return 1;
    }

    // naming both the files fin(.txt input file, .txt output file)
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);

    if(!fin || !fout){
        cout<<"Not able to open the file...";
    }   

    // Reading block size from file
    int blockSize;
    fin>>blockSize;

    // Number of row and column in matrix 1
    int r1, c1;
    fin >> r1 >> c1;

    // Fetching entries of Matrix A
    vector<vector<int>> A(r1, vector<int>(c1));
    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            fin >> A[i][j];
        }
    }

    // Fetching row and columns for Matrix B
    int r2, c2;
    fin >> r2 >> c2;

    // Fetching entries of Matrix A
    vector<vector<int>> B(r2, vector<int>(c2));
    for(int i=0; i<r2; i++){
        for(int j=0; j<c2; j++){
            fin >> B[i][j];
        }
    }

    // If col1 != row2 (Multiplication not possible)
    if(c1 != r2){
        fout<<"Matrix multiplication is not possible...";
        return 1;
    }

    auto start = high_resolution_clock::now();
    // call to the actual algorithms for blocking multiplication
    vector<vector<int>> C = blockMatrixMultiply(A, B, blockSize);
    auto stop = high_resolution_clock::now();

    double timeTaken = duration<double, milli>(stop - start).count();

    fout<<"Execution Time : "<< timeTaken <<" ms\n"; 
    fout<<"Result Matrix : \n";

    // Writing the final output in the output file
    for(auto &row : C){
        for(int val : row){
            fout << val << " ";
        }
        fout<<"\n";
    }

    // close both the files in the end
    fin.close();
    fout.close();
    return 0;
}