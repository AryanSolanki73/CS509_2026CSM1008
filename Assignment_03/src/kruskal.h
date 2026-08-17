#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "mst.h"
#include <vector>
using namespace std;

vector<MSTEdge> kruskalMST(const CSRGraph& graph, long long& totalWeight);

#endif