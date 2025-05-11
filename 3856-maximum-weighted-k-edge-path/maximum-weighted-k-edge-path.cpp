class Solution {
public:
   
    int dfs(int source,map<int,vector<pair<int,int>>>&mp,int k,int t,vector<vector<unordered_map<int, int>>>& dp){
        if(mp[source].size() == 0){
            if(k == 0)return 0;
            return -1e9;
        }
      
        if(k == 0 or t < 0){
            if(k == 0)return 0;
            return -1e9;
        }

        if(dp[source][k].count(t))return dp[source][k][t];
        int maxi = -1e9;
        for(auto &neigh: mp[source]){
           int inc = -1e9; 
           if(neigh.second < t)
             inc = neigh.second + dfs(neigh.first,mp,k-1,t-neigh.second,dp);
           maxi = max(maxi,inc);
        }
        return dp[source][k][t] = maxi;
    }
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        if(k == 0)return 0;
        if(edges.size() < k)return -1;
         map<int,vector<pair<int,int>>> mp;
      vector<vector<unordered_map<int, int>>> dp(n, vector<unordered_map<int, int>>(k + 1));
         for(int i=0;i<edges.size();i++){
             mp[edges[i][0]].push_back({edges[i][1],edges[i][2]});
         }
         int maxi = 0;
         for(int i=0;i<n;i++){
            int val = dfs(i,mp,k,t,dp);
            maxi = max(maxi,val);
         }

         return maxi == 0 ? -1 : maxi;

    }
};