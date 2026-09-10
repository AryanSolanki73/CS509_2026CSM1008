#ifndef PRIMS_H
#define PRIMS_H

#include "mst.h"    // including the CSR.h files 
#include <vector>
using namespace std;

// Algo used to find the minimum cost spanning tree, start from a vertex and a vertex by taking the minimum cost path
// start vertex always set to 0
// totalWeight = 0
vector<MSTEdge> primMST(const CSRGraph& graph, int startVertex,  long long&totalWeight);

#endif