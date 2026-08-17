#ifndef CSR_GRPAH   
#define CSE_GRAPH
#include<vector>
using namespace std;

// CSRGraph class (Template to convert adjacency list to CSR)
class CSRGraph
{
private:
    int vertices;
    int edges;

    vector<int> rowPtr;
    vector<int> colIndex;
    vector<int> weight;

public:
    CSRGraph(int V);
    void buildCSR(const vector<vector<int>>& adjList);
    int getVertices() const;
    int getEdges() const;
    const vector<int>& getRowPtr() const;
    const vector<int>& getColIndex() const;
    const vector<int>& getWeight() const;

    void displayCSR() const;
};

#endif