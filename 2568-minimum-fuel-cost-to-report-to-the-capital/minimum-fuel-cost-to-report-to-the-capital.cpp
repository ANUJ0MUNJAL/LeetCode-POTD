class Solution {
public:
    long long ans=0;
    long long dfs(int source,map<int,vector<int>>&mp,int seats,vector<int>&visited){
          
          visited[source]=1;
          
          long long count=0;
          for(auto neigh: mp[source])
          {
               if(!visited[neigh]){
                    int val=dfs(neigh,mp,seats,visited);
                    count+=val;
               }
          }
          count++;
          long long value=ceil(1.0*count/seats);
          if(source!=0)
          ans+=value;
        
          return count;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        map<int,vector<int>> mp;
        for(int i=0;i<roads.size();i++){
             mp[roads[i][0]].push_back(roads[i][1]);
             mp[roads[i][1]].push_back(roads[i][0]);
        }
        
        vector<int> visited(roads.size()+1,0);
         dfs(0,mp,seats,visited);
         return ans;
    }
};