#include "bellmanFord.h"
#include <climits>

using namespace std;

vector<long long> bellmanFord(const CSRGraph& graph,int source,bool& negativeCycle)
{
    const long long INF = LLONG_MAX / 4;
    int V = graph.vertices;
    vector<long long> distance(V, INF);
    negativeCycle = false;

    // Invalid source
    if (source < 0 || source >= V) {
        return {};
    }

    distance[source] = 0;

    // Relax all edges V-1 times
    for (int iteration = 0; iteration < V - 1; iteration++) {
        bool updated = false;
        for (int u = 0; u < V; u++) {
            // If u is unreachable, don't process it
            if (distance[u] == INF) {
                continue;
            }
            // CSR range for vertex u
            for (int i = graph.row_ptr[u]; i < graph.row_ptr[u + 1]; i++) {
                int v = graph.col[i];
                long long w = graph.weight[i]; 
                if (distance[u] + w < distance[v]) {
                    distance[v] = distance[u] + w;
                    updated = true;
                }
            }
        }

        // No changes -> already converged
        if (!updated) {
            break;
        }
    }

    // -------------------------------------------------
    // Check for negative-weight cycle reachable
    // from source
    // -------------------------------------------------

    for (int u = 0; u < V; u++) {
        if (distance[u] == INF) {
            continue;
        }

        for (int i = graph.row_ptr[u]; i < graph.row_ptr[u + 1]; i++) {
            int v = graph.col[i];
            long long w = graph.weight[i];
            if (distance[u] + w < distance[v]) {
                negativeCycle = true;
                return {};
            }
        }
    }
    return distance;
}