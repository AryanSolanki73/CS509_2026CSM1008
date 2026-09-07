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
        // parent vector of size n
        parent.resize(n);

        // rankValue vector of size n with all entries as 0 
        rankValue.resize(n, 0);

        // fill the value of parent in increasing order 1 to n
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

    // Vector of Object of MSTEdge whcich have (u, v, weight)
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

    // Outer loop run for #vertices time 
    for (int u = 0; u < graph.vertices; u++) {

        // To fetch all the edges and weights 
        for (int i = graph.row_ptr[u]; i < graph.row_ptr[u + 1]; i++) {

            // fetch a vertex from col
            int v = graph.col[i];
            long long w = graph.weight[i];

            // To remove the duplicacy of the edges
            if (u < v) {
                edges.push_back({u, v, w});
            }
        }
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end(),
    // lambda function takes 2 edges and decide which one we should choose
    [](const MSTEdge& a, const MSTEdge& b) {
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

    // vector of object of MSTEdge class
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