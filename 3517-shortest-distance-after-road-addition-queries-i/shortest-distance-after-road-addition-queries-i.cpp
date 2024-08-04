class Solution {
public:
        int  dijkstra(int src,int dst,map<int,vector<pair<int,int>>>&adj){
      vector<int>dist(dst+1,1e9);
      queue<pair<int,int>>q;
      
      dist[0]=0;
      q.push({0,0});
      while(!q.empty()){
      int node=q.front().first;
          q.pop();
          for(auto it:adj[node]){
              int newnode=it.first;
              int newdis=it.second;
              if(newdis+dist[node]<dist[newnode]){
                  dist[newnode]=newdis+dist[node];
                  q.push({newnode,newdis+dist[node]});
              }
          }
      }
      return dist[dst];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
         map<int,vector<pair<int,int>>> mp;
        for(int i=0;i<n-1;i++){
              mp[i].push_back({i+1,1});
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            mp[queries[i][0]].push_back({queries[i][1],1});
            ans.push_back(dijkstra(0,n-1,mp));
        }
        return ans;
    }
};