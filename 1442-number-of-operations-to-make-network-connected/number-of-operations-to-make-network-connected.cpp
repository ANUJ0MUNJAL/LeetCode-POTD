
#include <bits/stdc++.h>
using namespace std;
class DisjointSet {
    vector<int> rank, parent, size; 
public: 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
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
   
    int makeConnected(int n, vector<vector<int>>& connections) {
         DisjointSet ds(n);
         int count=0;
         for(int i=0;i<connections.size();i++)
         {
              int a = ds.findUPar(connections[i][0]);
              int b = ds.findUPar(connections[i][1]);
              if(a == b)count++;
              ds.unionByRank(connections[i][0],connections[i][1]);
         }
         vector<int> parent(n);
         map<int,int> m;
         for(int i=0;i<n;i++)
         {
             parent[i]=ds.findUPar(i);
             m[parent[i]]++;
         }
         multiset<int> st;
         
         for(auto j: m)
         {
             st.insert(j.second);
         }
        //  for(auto j: st)cout<<j<<" ";
        // cout<<count<<" ";
         int ans=0;
         while(st.size()!=1)
         {
              auto el = *st.begin();
              st.erase(st.find(el));
              ans++;
         }
         
         if(ans <= count)return ans;
         return -1;
           
    }
};