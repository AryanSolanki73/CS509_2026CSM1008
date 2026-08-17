#ifndef PRIMS_H
#define PRIMS_H

#include "mst.h"
#include <vector>
using namespace std;

vector<MSTEdge> primMST(const CSRGraph& graph, int startVertex,  long long&totalWeight);

#endif