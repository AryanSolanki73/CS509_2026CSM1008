#include <bits/stdc++.h>
#include "prims.h"
#include <queue>
#include <tuple>
#include <vector>
#include <functional>
using namespace std;

// Prim's Minimum Spanning Tree
vector<MSTEdge> primMST(const CSRGraph& graph, int startVertex, long long& totalWeight) {
    totalWeight = 0;
    int V = graph.vertices;

    // Validate starting vertex
    if (startVertex < 0 || startVertex >= V) {
        return {};
    }

    // Min-heap
    //
    // {edge weight, vertex, parent}
    using PQNode = tuple<long long, int, int>;
    priority_queue<PQNode, vector<PQNode>, greater<PQNode>> pq;
    vector<bool> visited(V, false);
    vector<MSTEdge> mst;

    // Start from startVertex
    pq.push({0, startVertex, -1});
    
    // Prim's algorithm
    while (!pq.empty()) {
        auto [weight, u, parent] = pq.top();
        pq.pop();

        // Vertex already included in MST
        if (visited[u]) {
            continue;
        }

        visited[u] = true;

        // First vertex has no parent
        if (parent != -1) {
            mst.push_back({parent, u, weight});
            totalWeight += weight;
        }

        // Traverse neighbours using CSR
        for (int i = graph.row_ptr[u]; i < graph.row_ptr[u + 1]; i++) {
            int v = graph.col[i];
            long long w = graph.weight[i];
            if (!visited[v]) {
                pq.push({w, v, u});
            }
        }
    }

    // Check if graph is connected
    if (static_cast<int>(mst.size()) != V - 1) {
        totalWeight = 0;
        return {};
    }
    return mst;
}