#include <iostream>
#include <vector>
using namespace std;
class DisjointSet {
    vector<int> rank, parent;
    DisjointSet(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for (int i = 0; i < n+1; i++) {
            parent[i] = i;
        }
    }
    int findUParent(int node) {
        if (parent[node] != node) {
            parent[node] = findUParent(parent[node]);
        }
        return parent[node];
    }

    void unionByRank(int u, int v) {
        int uParent = findUParent(u);
        int vParent = findUParent(v);
        if (uParent == vParent) return;
        if (rank[uParent] < rank[vParent]) {
            parent[uParent] = vParent;
        }
        else if (rank[uParent] > rank[vParent]) {
            parent[vParent] = uParent;
        }
        else {
            parent[vParent] = uParent;
            rank[uParent]++;
        }
    }
};