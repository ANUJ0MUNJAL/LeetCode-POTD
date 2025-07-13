#include <bits/stdc++.h>
using namespace std;
class DisjointSet {
    vector<int> rank, parent, size; 
public: 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0; i <= n; i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
};

class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        return a[2] < b[2];
    }
    int minCost(int n, vector<vector<int>>& edges, int k) {
        sort(edges.begin(),edges.end(),cmp);
        int count = n;
        DisjointSet ds(n);
        if(k >= n)return 0;
        for(int i=0;i<edges.size();i++)
        {
            int u = ds.findUPar(edges[i][0]);
            int v = ds.findUPar(edges[i][1]);
            if(u != v)
            {
                count--;
                ds.unionByRank(u,v);
                if(count <= k)return edges[i][2];
            }
        }
        return 0;
    }
};