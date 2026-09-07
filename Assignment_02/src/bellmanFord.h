#ifndef BELLMAN_FORD_H
#define BELLMAN_FORD_H

// This algorithm used to find single source shortest path for negative edge weights as well, create problem for negative weight cycle

#include "csr.h"
#include <vector>
using namespace std;

// Bellman ford algorith used to find the shortest path between a source to all other vertices (for weighted, undirected graphs)
// can handle negative edge weight but the negative edge weight cycle
vector<long long> bellmanFord(const CSRGraph& graph, int source, bool& negativeCycle);

#endif