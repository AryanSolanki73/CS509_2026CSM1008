#include<iostream>          // Standard input ouput 
#include<fstream>           // File input ouput 
#include<chrono>            //Timing information 
#include<vector>            // Vector library
#include "../src/matrix.h"  // definition of functions declared in .h file
using namespace std;
using namespace chrono;

// argc = count of total command line arguments
// argv = Actual arguments comming from command line argument
int main(int argc, char* argv[]){
    if(argc != 3){
        // Executable file | inputfile | outputfile | from command line
        cout<<"Usage : main inputFile outputFile\n";
        return 1;
    }

    ifstream fin(argv[1]);  // Input file system
    ofstream fout(argv[2]); // Output file system

    // If files are not opening
    if(!fin || !fout){
        cout<<"Not able to open the file...";
    }   

    // Reading #rows and #col from the file
    // ">>" : remove the spaces, newline from the text
    int r1, c1;
    fin>>r1>>c1;

    // Taking a 2-D vector(Matrix) from the input file
    vector<vector<int>> A(r1, vector<int>(c1));
    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            fin >> A[i][j];
        }
    }

    // 
    int r2, c2;
    fin>>r2>>c2;

    vector<vector<int>> B(r2, vector<int>(c2));
    for(int i=0; i<r2; i++){
        for(int j=0; j<c2; j++){
            fin>>B[i][j];
        }
    }

    if(c1 != r2){
        fout<<"Matrix multiplication is not possible...";
        return 1;
    }

    auto start = high_resolution_clock::now();

    vector<vector<int>> C = multiplyMatrices(A, B);

    auto stop = high_resolution_clock::now();

    double timeTaken = duration<double, milli>(stop - start).count();

    fout<<"Execution Time : "<< timeTaken <<" ms\n";

    fout<<"Result Matrix : \n";

    for(auto &row : C){
        for(int val : row){
            fout << val << " ";
        }
        fout<<"\n";
    }

    fin.close();
    fout.close();
    return 0;
}