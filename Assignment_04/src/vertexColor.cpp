#include "vertexColor.h"
#include <algorithm>
#include <numeric>
using namespace std;

// Welsh-Powell greedy vertex coloring.
// Reference: https://graphstream-project.org/doc/Algorithms/Welsh-Powell
//
// Steps:
//   1. Compute the degree of every vertex directly from the CSR row_ptr.
//   2. Order vertices by non-increasing degree.
//   3. Process vertices in that order; assign each vertex the smallest
//      color index not already used by any already-colored neighbour.
vector<int> greedyVertexColoring(const CSRGraph& graph) {
    int V = graph.vertices;
    vector<int> colors(V, -1);

    if (V == 0) return colors;

    // Step 1: degree of every vertex from CSR (O(V)).
    vector<int> degree(V);
    for (int v = 0; v < V; v++) {
        degree[v] = graph.row_ptr[v + 1] - graph.row_ptr[v];
    }

    // Step 2: order vertices by non-increasing degree (Welsh-Powell).
    vector<int> order(V);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int a, int b) {
        if (degree[a] != degree[b]) return degree[a] > degree[b];
        return a < b; // stable tie-break for reproducibility
    });

    // Step 3: greedily color each vertex in that order.
    // usedByNeighbour is reused per-vertex to avoid reallocating each time.
    vector<char> usedByNeighbour; // grows as needed
    for (int idx = 0; idx < V; idx++) {
        int u = order[idx];

        // Determine which colors are already used by colored neighbours.
        usedByNeighbour.assign(1, 0); // will grow lazily below
        int maxSeen = -1;
        for (int e = graph.row_ptr[u]; e < graph.row_ptr[u + 1]; e++) {
            int nb = graph.col_idx[e];
            int c = colors[nb];
            if (c >= 0) {
                if (c > maxSeen) {
                    usedByNeighbour.resize(c + 1, 0);
                    maxSeen = c;
                }
                usedByNeighbour[c] = 1;
            }
        }

        // Smallest color index not used by any already-colored neighbour.
        int chosen = 0;
        while (chosen < (int)usedByNeighbour.size() && usedByNeighbour[chosen]) {
            chosen++;
        }
        colors[u] = chosen;
    }

    return colors;
}

int countColorsUsed(const vector<int>& colors) {
    int maxColor = -1;
    for (int c : colors) {
        maxColor = max(maxColor, c);
    }
    return maxColor + 1;
}

bool isValidColoring(const CSRGraph& graph, const vector<int>& colors) {
    for (int u = 0; u < graph.vertices; u++) {
        for (int e = graph.row_ptr[u]; e < graph.row_ptr[u + 1]; e++) {
            int v = graph.col_idx[e];
            if (colors[u] == colors[v]) {
                return false;
            }
        }
    }
    return true;
}
