#ifndef BELLMAN_FORD_H
#define BELLMAN_FORD_H
#include "csr.h"
#include <vector>
using namespace std;

vector<long long> bellmanFord(const CSRGraph& graph, int source, bool negativeCycle);

#endif