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

    ifstream fin(argv[1]);
    ofstream fout(argv[2]);

    if(!fin || !fout){
        cout<<"Not able to open file..\n";
    }

    int V, E;
    fin >> V >> E;

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