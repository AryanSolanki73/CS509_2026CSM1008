#include"CSR.h"
#include<iostream>

using namespace std;

CSRGraph::CSRGraph(int V){
    vertices = V;
    edges = 0;
}

void CSRGraph::buildCSR(const vector<vector<int>>& adjList){
    rowPtr.clear();
    colIndex.clear();

    rowPtr.push_back(0);

    edges = 0;
    for(int i=0; i<vertices; i++){
        for(int neighbour : adjList[i]){
            colIndex.push_back(neighbour);
            edges++;
        }
        rowPtr.push_back(edges);
    }
}

int CSRGraph::getVertices() const{
    return vertices;
}

int CSRGraph::getEdges() const{
    return edges;
}

const vector<int>& CSRGraph::getRowPtr() const{
    return rowPtr;
}

const vector<int>& CSRGraph::getColIndex() const{
    return colIndex;
}

const vector<int>& CSRGraph::getWeight() const{
    return weight;
}
void CSRGraph::displayCSR() const{
    cout<<"\nRow Pointer\n";
    for(int x : rowPtr){
        cout<<x<<" ";
    }

    cout<<"\nColumn Index\n";
    for(int x : colIndex){
        cout<<x<<" ";
    }
    cout<<endl;
}
