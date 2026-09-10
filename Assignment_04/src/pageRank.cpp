#include "pageRank.h"
#include <cmath>

using namespace std;


// Calculates PageRank for all vertices
PageRankResult pageRank(
    const CSRGraph& graph,
    double damping,
    double tolerance,
    int maxIterations) {

    int V = graph.vertices;
    PageRankResult result;

    // Handle an empty graph
    if (V == 0) {
        result.converged = true;
        return result;
    }

    // Calculate outdegree of every vertex using CSR
    vector<int> outdegree(V);

    for (int v = 0; v < V; v++) {
        outdegree[v] = graph.row_ptr[v + 1] - graph.row_ptr[v];
    }


    // Initially, every vertex gets equal PageRank
    // PR(v) = 1 / V
    vector<double> rank(V, 1.0 / V);

    // Stores PageRank values for the next iteration
    vector<double> next(V, 0.0);

    int iter = 0;
    bool converged = false;


    // Repeat PageRank calculation until convergence
    // or maximum iterations are reached
    for (iter = 0; iter < maxIterations; iter++) {

        // Calculate total rank of dangling vertices
        // (vertices having no outgoing edges)
        double danglingSum = 0.0;

        for (int u = 0; u < V; u++) {
            if (outdegree[u] == 0)
                danglingSum += rank[u];
        }


        // Base PageRank given to every vertex
        // Also distributes dangling vertex rank equally
        double base =
            (1.0 - damping) / V
            + damping * danglingSum / V;


        // Start every vertex with the base value
        for (int v = 0; v < V; v++) {
            next[v] = base;
        }


        // Distribute PageRank through outgoing edges
        for (int u = 0; u < V; u++) {

            // Dangling vertices were already handled above
            if (outdegree[u] == 0)
                continue;

            // Rank contributed by u to each outgoing neighbour
            double share =
                damping * rank[u] / outdegree[u];


            // Traverse u's neighbours using CSR
            for (int e = graph.row_ptr[u];
                 e < graph.row_ptr[u + 1];
                 e++) {

                int v = graph.col_idx[e];

                // Add u's contribution to v
                next[v] += share;
            }
        }


        // Calculate the total change in PageRank
        double totalChange = 0.0;

        for (int v = 0; v < V; v++) {
            totalChange += fabs(next[v] - rank[v]);
        }


        // Make the new ranks the current ranks
        rank.swap(next);


        // Stop if the change is small enough
        if (totalChange <= tolerance) {
            converged = true;

            // Count this iteration as completed
            iter++;

            break;
        }
    }


    // If convergence was not reached, maximum iterations were used
    if (!converged) {
        iter = maxIterations;
    }


    // Store final results
    result.ranks = rank;
    result.iterations = iter;
    result.converged = converged;

    return result;
}