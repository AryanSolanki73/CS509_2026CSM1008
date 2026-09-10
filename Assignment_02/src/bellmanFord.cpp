#include "bellmanFord.h"   // importing the declaration for bellmanFord
#include <climits>   // LLONG_MAX defined in it.
using namespace std;

// inputs = (CSR graph, source vertex, bool value to chech graph has neg. cycle or not)
vector<long long> bellmanFord(const CSRGraph& graph, int source, bool& negativeCycle)
{
const long long INF = LLONG_MAX / 4;  // A very large number considered as INF  
    // Total number of vertices in the graph
    int V = graph.vertices;

    // distance to all the vertices are intialize with INF
    vector<long long> distance(V, INF);
    
    // currently no negative cycle
    negativeCycle = false;

    // Invalid source
    if (source < 0 || source >= V) {
        return {};
    }

    // source vetex is intialize with 0 (distance from source to source is 0)
    distance[source] = 0;

    // Relax all edges V-1 times
    for (int iteration = 0; iteration < V - 1; iteration++) {
        // intilialized every time 
        bool updated = false;
        for (int u = 0; u < V; u++) {

            // If u is unreachable, don't process it
            // distance[0] = 0, current source distance already filled
            if (distance[u] == INF) {
                continue;
            }

            // CSR range for vertex u 
            for (int i = graph.row_ptr[u]; i < graph.row_ptr[u + 1]; i++) {
                // Extracting the edges from colIndex
                int v = graph.col[i];

                // Extracting the weightes from weight index
                long long w = graph.weight[i]; 

                // after adding the w if the distance become less than previous, then change the distance to new one
                if (distance[u] + w < distance[v]) {
                    distance[v] = distance[u] + w;

                    // set updates flag as true
                    // update each vertex distance once in the iteration of u
                    updated = true;
                }
            }
        }

        // No changes -> already converged
        if (!updated) {
            break;
        }
    }

    // Check for negative-weight cycle reachable from source, we run the relaxation loop for V times
    for (int u = 0; u < V; u++) {
        if (distance[u] == INF) {
            continue;
        }

        // Logic to check the cycle in the graph or not
        for (int i = graph.row_ptr[u]; i < graph.row_ptr[u + 1]; i++) {
            int v = graph.col[i];
            long long w = graph.weight[i];
            if (distance[u] + w < distance[v]) {
                negativeCycle = true;
                return {};
            }
        }
    }

    // returning finl distances
    return distance;
}