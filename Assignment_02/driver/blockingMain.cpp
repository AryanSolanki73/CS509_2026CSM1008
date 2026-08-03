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

    ifstream fin(argv[1]);
    ofstream fout(argv[2]);

    if(!fin || !fout){
        cout<<"Not able to open the file...";
    }   

    int r1, c1;
    fin >> r1 >> c1;

    vector<vector<int>> A(r1, vector<int>(c1));
    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            fin >> A[i][j];
        }
    }

    int r2, c2;
    fin >> r2 >> c2;

    vector<vector<int>> B(r2, vector<int>(c2));
    for(int i=0; i<r2; i++){
        for(int j=0; j<c2; j++){
            fin >> B[i][j];
        }
    }
    if(c1 != r2){
        fout<<"Matrix multiplication is not possible...";
        return 1;
    }

    auto start = high_resolution_clock::now();

    vector<vector<int>> C = blockMatrixMultiply(A, B, 2);

    auto stop = high_resolution_clock::now();

    double timeTaken = duration<double, milli>(stop - start).count();

    fout<<"Result Matrix : \n";

    for(auto &row : C){
        for(int val : row){
            fout << val << " ";
        }
        fout<<"\n";
    }

    fout<<"Execution Time : "<< timeTaken <<" ms\n";
    fin.close();
    fout.close();
    return 0;
}