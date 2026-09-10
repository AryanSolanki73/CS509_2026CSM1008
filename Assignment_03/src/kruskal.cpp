#include <bits/stdc++.h>
#include "kruskal.h"
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

// Disjoint Set Union
class DSU {

private:
    // parent[i] stores the parent of vertex i.
    //
    // Initially:
    // parent[0] = 0
    // parent[1] = 1
    // parent[2] = 2
    // ...
    //
    // This means every vertex is initially
    // the parent of itself.
    vector<int> parent;


    // rankValue[i] stores the "rank" (approximate height)
    // of the tree whose root is i.
    //
    // We use rank to keep the DSU tree short.
    // Initially, every vertex is a separate tree of height 0.
    vector<int> rankValue;


public:

    // Constructor
    // n = number of vertices
    DSU(int n) {

        // Create parent array of size n.
        parent.resize(n);


        // Create rank array of size n.
        // Initially, rank of every vertex is 0.
        rankValue.resize(n, 0);


        // Make every vertex its own parent.
        //
        // iota fills the array like:
        //
        // parent = {0, 1, 2, 3, 4, ...}
        //
        // So initially:
        //
        // 0 is parent of 0
        // 1 is parent of 1
        // 2 is parent of 2
        // ...
        //
        // Therefore, every vertex is a separate component.
        iota(parent.begin(), parent.end(), 0);
    }


    // ----------------------------------------------------
    // FIND OPERATION
    // ----------------------------------------------------
    //
    // find(x) tells us:
    //
    // "Which component does vertex x belong to?"
    //
    // More specifically, it returns the ROOT of x.
    //
    // Path compression is used to make future find()
    // operations faster.
    int find(int x) {

        // If x is NOT its own parent,
        // then x is not the root.
        if (parent[x] != x) {

            // Recursively find the root.
            //
            // Then directly make x point to the root.
            //
            // This is called PATH COMPRESSION.
            parent[x] = find(parent[x]);
        }


        // Return the root of x.
        return parent[x];
    }


    // ----------------------------------------------------
    // UNION OPERATION
    // ----------------------------------------------------
    //
    // unite(a, b) tries to combine the components
    // containing vertices a and b.
    //
    // Returns:
    // true  -> components were successfully merged
    // false -> a and b were already in the same component
    bool unite(int a, int b) {


        // Find the root of vertex a.
        //
        // IMPORTANT:
        // We don't simply use parent[a].
        // We use find(a) because a may be somewhere
        // inside a larger tree.
        int rootA = find(a);


        // Find the root of vertex b.
        int rootB = find(b);


        // If both vertices have the same root,
        // they already belong to the same component.
        //
        // Connecting them would create a CYCLE.
        if (rootA == rootB) {
            return false;
        }


        // ------------------------------------------------
        // UNION BY RANK
        // ------------------------------------------------
        //
        // We attach the smaller tree under the larger tree.
        //
        // This keeps the DSU tree short and makes
        // find() operations faster.

        if (rankValue[rootA] < rankValue[rootB]) {

            // Tree of rootA is smaller,
            // so attach rootA under rootB.
            parent[rootA] = rootB;
        }


        else if (rankValue[rootA] > rankValue[rootB]) {

            // Tree of rootB is smaller,
            // so attach rootB under rootA.
            parent[rootB] = rootA;
        }


        else {

            // Both trees have the same rank.
            //
            // We can choose either root.
            // Here, we make rootA the parent of rootB.
            parent[rootB] = rootA;

            // Since two trees of equal height were merged,
            // the height of the resulting tree increases by 1.
            rankValue[rootA]++;
        }


        // The two components were successfully merged.
        return true;
    }
};

// Kruskal's Minimum Spanning Tree logic
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
                // Now we have all the edges with 2 vertices and 
                // weight between them
                edges.push_back({u, v, w});
            }
        }
    }

    // Sort edges by weight, if weights are equal then on the basis of u
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
    // Object of DSU
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
    // there must be v-1 edges in graph to be connected
    if (static_cast<int>(mst.size()) != graph.vertices - 1) {
        totalWeight = 0;
        return {};
    }

    // return the final mst with {u, v, w};
    return mst;
}