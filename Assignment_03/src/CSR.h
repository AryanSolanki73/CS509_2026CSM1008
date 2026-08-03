#ifndef CSR_GRPAH
#define CSE_GRAPH
#include<vector>
using namespace std;

class CSRGraph
{
private:
    int vertices;
    int edges;

    vector<int> rowPtr;
    vector<int> colIndex;

public:
    CSRGraph(int V);
    void buildCSR(const vector<vector<int>>& adjList);
    int getVertices() const;
    int getEdges() const;
    const vector<int>& getRowPtr() const;
    const vector<int>& getColIndex() const;

    void displayCSR() const;
};

#endif