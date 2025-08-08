#include <iostream>
#include <vector>
using namespace std;
class DisjointSet
{
    vector<int> rank, parent, size;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i < n + 1; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUParent(int node)
    {
        if (parent[node] != node)
        {
            parent[node] = findUParent(parent[node]);
        }
        return parent[node];
    }

    void unionByRank(int u, int v)
    {
        int uParent = findUParent(u);
        int vParent = findUParent(v);
        if (uParent == vParent)
            return;
        if (rank[uParent] < rank[vParent])
        {
            parent[uParent] = vParent;
        }
        else if (rank[uParent] > rank[vParent])
        {
            parent[vParent] = uParent;
        }
        else
        {
            parent[vParent] = uParent;
            rank[uParent]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};