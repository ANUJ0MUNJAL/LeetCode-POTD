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
    
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
          DisjointSet ds(n);

          vector<int> cost(n,INT_MAX);

          for(int i=0;i<edges.size();i++){
                int u=edges[i][0];
                int v=edges[i][1];
                int w=edges[i][2];
                
                int upar=ds.findUPar(u);
                int vpar=ds.findUPar(v);

                if(upar == vpar){
                  cost[upar]&=w;
                   continue;
                }
                ds.unionByRank(upar,vpar);
                int p=ds.findUPar(upar);
                if(p==upar){
                    cost[p]&=cost[vpar];
                    cost[p]&=w;
                }else{
                    cost[p]&=cost[upar];
                    cost[p]&=w;
                }
                cout<<cost[upar]<<"\n";
                
          }

    
            vector<int> temp;
          for(auto j:  query){
            if(j[0]==j[1]){
              temp.push_back(0);
              continue;
            }

            int upar=ds.findUPar(j[0]);
            int vpar=ds.findUPar(j[1]);
           
            if(upar==vpar){
               temp.push_back(cost[upar]);
            }else{
               temp.push_back(-1);
            }

          }
          return temp;
      
    }
};