#include "pageRank.h"
#include <cmath>
using namespace std;

// Reference: https://web.stanford.edu/class/cs106m/meetings/03-pagerank
PageRankResult pageRank(const CSRGraph& graph, double damping, double tolerance, int maxIterations) {
    int N = graph.vertices;
    PageRankResult result;

    if (N == 0) {
        result.converged = true;
        return result;
    }

    // Outdegree of every vertex, straight from CSR row_ptr (O(V)).
    vector<int> outdegree(N);
    for (int v = 0; v < N; v++) {
        outdegree[v] = graph.row_ptr[v + 1] - graph.row_ptr[v];
    }

    // All vertices initialized with rank 1/N.
    vector<double> rank(N, 1.0 / N);
    vector<double> next(N, 0.0);

    int iter = 0;
    bool converged = false;

    for (iter = 0; iter < maxIterations; iter++) {
        // Base term (1 - d) / N for every vertex, plus an even share of
        // dangling-vertex rank (outdegree 0 vertices distribute their
        // rank evenly across ALL vertices).
        double danglingSum = 0.0;
        for (int u = 0; u < N; u++) {
            if (outdegree[u] == 0) danglingSum += rank[u];
        }
        double base = (1.0 - damping) / N + damping * danglingSum / N;

        for (int v = 0; v < N; v++) next[v] = base;

        // Distribute rank along outgoing edges: for every edge u -> v,
        // add PR(u) / outdegree(u) to next[v]. All vertices updated
        // simultaneously using the PREVIOUS iteration's rank values.
        for (int u = 0; u < N; u++) {
            if (outdegree[u] == 0) continue; // handled via danglingSum above
            double share = damping * rank[u] / outdegree[u];
            for (int e = graph.row_ptr[u]; e < graph.row_ptr[u + 1]; e++) {
                int v = graph.col_idx[e];
                next[v] += share;
            }
        }

        // Total change (sum of absolute differences) across all vertices.
        double totalChange = 0.0;
        for (int v = 0; v < N; v++) {
            totalChange += fabs(next[v] - rank[v]);
        }

        rank.swap(next);

        if (totalChange <= tolerance) {
            converged = true;
            iter++; // count this iteration as completed
            break;
        }
    }

    if (!converged) {
        iter = maxIterations;
    }

    result.ranks = rank;
    result.iterations = iter;
    result.converged = converged;
    return result;
}
