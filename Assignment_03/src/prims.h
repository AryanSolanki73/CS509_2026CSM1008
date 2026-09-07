#ifndef PRIMS_H
#define PRIMS_H

#include "mst.h"    // including the CSR.h files 
#include <vector>
using namespace std;

vector<MSTEdge> primMST(const CSRGraph& graph, int startVertex,  long long&totalWeight);

#endif