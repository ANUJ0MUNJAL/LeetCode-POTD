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

// [[2,1],[3,1],[4,2],[1,4]]
// 2 --- > 1 
// ^       ^
// |       |
// 4       3

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {

         vector<int> indegree(edges.size()+1,-1);
         int possible=-1,possible1=-1;
         int val=0;
         for(int i=0;i<edges.size();i++){
            if(indegree[edges[i][1]] != -1){
                possible=indegree[edges[i][1]];
                possible1=i;
                break;
            }else{
                 indegree[edges[i][1]]=val;
                 val++;
            }
         }
         
          DisjointSet ds(edges.size());

          if(possible == -1 and possible1 == -1){
               
                for(int i=0;i<edges.size();i++){
                   int u=ds.findUPar(edges[i][0]);
                   int v=ds.findUPar(edges[i][1]);
                   
                   if(u == v){
                     return {edges[i][0],edges[i][1]};
                   }else{
                    ds.unionByRank(edges[i][0],edges[i][1]);
                   }
                }

          }else{
              
               for(int i=0;i<edges.size();i++){
                   int u=ds.findUPar(edges[i][0]);
                   int v=ds.findUPar(edges[i][1]);
                   
                   if(i == possible || i == possible1){
                         continue;
                   }else{
                    ds.unionByRank(edges[i][0],edges[i][1]);
                   }

            
               }

               int u=ds.findUPar(edges[possible][0]);
               int v=ds.findUPar(edges[possible][1]);
               
               if(u == v){
                   return {edges[possible][0],edges[possible][1]};
               }else{
                   return {edges[possible1][0],edges[possible1][1]};
               }

          }

         return {};

    }
};