#ifndef PAGE_RANK_H
#define PAGE_RANK_H

#include <vector>
#include "csr.h"
using namespace std;

struct PageRankResult {
    vector<double> ranks;
    int iterations = 0;
    bool converged = false;
};

// PageRank on an unweighted, directed CSR graph.
//
// PR(v) = (1 - d) / N + d * sum over u -> v of ( PR(u) / outdegree(u) )
//
// Dangling vertices (outdegree 0) distribute their rank evenly across
// ALL vertices, as permitted by Section 2.2 of the assignment.
//
// Iterates using the previous iteration's values for every vertex
// simultaneously, until the sum of absolute differences across all
// vertices is <= tolerance, or maxIterations is reached.
PageRankResult pageRank(const CSRGraph& graph, double damping, double tolerance, int maxIterations);

#endif // PAGE_RANK_H
