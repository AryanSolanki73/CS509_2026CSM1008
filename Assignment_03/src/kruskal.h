#ifndef KRUSKAL_H  
#define KRUSKAL_H

#include "mst.h"   // Giving the header file of csr.h
#include <vector>
using namespace std;

// This is a minimum cost spanning tree algorithm, sort the all edge weights and return the tree made of the smallest edge weights
vector<MSTEdge> kruskalMST(const CSRGraph& graph, long long& totalWeight);

#endif