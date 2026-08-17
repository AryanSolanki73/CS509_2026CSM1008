#include <bits/stdc++.h>
#include "kruskal.h"
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

// Disjoint Set Union
class DSU {
private:
    vector<int> parent;
    vector<int> rankValue;

public:
    DSU(int n) {
        parent.resize(n);
        rankValue.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    // Find with path compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Union by rank
    bool unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        // Already in same component
        if (rootA == rootB) {
            return false;
        }

        if (rankValue[rootA] < rankValue[rootB]) {
            parent[rootA] = rootB;
        }

        else if (rankValue[rootA] > rankValue[rootB]) {
            parent[rootB] = rootA;
        }

        else {
            parent[rootB] = rootA;
            rankValue[rootA]++;
        }
        return true;
    }
};

// Kruskal's Minimum Spanning Tree
vector<MSTEdge> kruskalMST(const CSRGraph& graph, long long& totalWeight) {
    totalWeight = 0;
    vector<MSTEdge> edges;

    // --------------------------------------------------------
    // Convert CSR -> edge list
    //
    // Since graph is undirected, every edge occurs twice:
    //
    // 0 -> 1
    // 1 -> 0
    //
    // We keep only u < v.
    // --------------------------------------------------------

    for (int u = 0; u < graph.vertices; u++) {
        for (int i = graph.row_ptr[u]; i < graph.row_ptr[u + 1]; i++) {
            int v = graph.col[i];
            long long w = graph.weight[i];
            if (u < v) {
                edges.push_back({u, v, w});
            }
        }
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end(), [](const MSTEdge& a, const MSTEdge& b) {
            if (a.weight != b.weight) {
                return a.weight < b.weight;
            }
            if (a.u != b.u) {
                return a.u < b.u;
            }
            return a.v < b.v;
        }
    );

    // Kruskal
    DSU dsu(graph.vertices);
    vector<MSTEdge> mst;
    for (const MSTEdge& edge : edges) {
        if (dsu.unite(edge.u, edge.v)) {
            mst.push_back(edge);
            totalWeight += edge.weight;

            // MST contains V - 1 edges
            if (static_cast<int>(mst.size()) == graph.vertices - 1) {
                break;
            }
        }
    }

    // Check if graph is connected
    if (static_cast<int>(mst.size()) != graph.vertices - 1) {
        totalWeight = 0;
        return {};
    }
    return mst;
}