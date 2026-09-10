#include<iostream>
#include<fstream>
#include<vector>
#include<chrono>
#include"../src/CSR.h"
using namespace std;

int main(int argc, char* argv[]){
    if(argc != 3){
        cout<<"Usages : CSR Inputfile Outputfile";
    }

    // taking input file in fin
    ifstream fin(argv[1]);
    // Taking output file in fout
    ofstream fout(argv[2]);

    if(!fin || !fout){
        cout<<"Not able to open file..\n";
    }

    // Fetching vertex and edges from input file
    int V, E;
    fin >> V >> E;

    // This unweighted and undirected graph
    vector<vector<int>> adj(V);
    for(int i=0; i<E; i++){
        int u, v;
        fin>>u>>v;
        adj[u].push_back(v);
        // For undirected graph 
        // adj[v].push_back(u)
    }

    CSRGraph graph(V);
    auto start = chrono::high_resolution_clock::now();
    graph.buildCSR(adj);
    auto stop = chrono::high_resolution_clock::now();

    double timeTaken = chrono::duration<double, milli>(stop - start).count();
    
    fout<<" Vertices : "<<graph.getVertices()<<'\n';
    fout<<" Edges : "<<graph.getEdges()<<"\n\n";

    fout<<"Execution Time : "<<timeTaken<<" ms\n";

    fout<<"Row Pointer : ";
    for(int x : graph.getRowPtr()){
        fout<<x<<" ";
    }
    fout<<"\nColumn Index : ";
    for(int x : graph.getColIndex()){
        fout<<x<<" ";
    }

    fin.close();
    fout.close();
}