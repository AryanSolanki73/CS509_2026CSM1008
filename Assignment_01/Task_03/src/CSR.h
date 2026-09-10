#ifndef CSR_GRPAH   
#define CSE_GRAPH
#include<vector>
using namespace std;

// CSRGraph (Template to convert adjacency list to CSR)
struct CSRGraph
{
    int vertices;
    int edges;

    vector<int> rowPtr;
    vector<int> colIndex;
    vector<int> weight;

    CSRGraph(int V);
    void buildCSR(const vector<vector<int>>& adjList);
    int getVertices();
    int getEdges();
    const vector<int>& getRowPtr() const;
    const vector<int>& getColIndex() const;
    const vector<int>& getWeight() const;
    void displayCSR() ;
};
#endif