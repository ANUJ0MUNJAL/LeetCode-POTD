class Solution {
public:
    bool bipartite(unordered_map<int,vector<int>> &mp,int source,vector<int>&visited,vector<int>&color,int prev)
    {
          color[source]=prev;
          
          for(auto j: mp[source])
          {
                 if(color[j] == color[source])return false;
                if(color[j] == -1)
                {
                    if(bipartite(mp,j,visited,color,!prev)==false)return false;
                }
          }
          return true;
    }
    int bfs(unordered_map<int,vector<int>>&mp,int source,int n)
    {
        queue<int> q;
        vector<int> visited(n+1,0);
        q.push(source);
        visited[source]=1;
        int level = 0;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                auto el = q.front();
                q.pop();
               

                for(auto j: mp[el])
                {
                    if(!visited[j])
                    {
                        q.push(j);
                        visited[j]=1;
                    }
                }
            }
        level++;
        }
        return level;
    }
    void dfs(unordered_map<int,vector<int>>&mp,vector<int>&visited,int source,int &val,vector<int>&temp)
    {
        visited[source]=1;
        val=max(val,temp[source]);
        for(auto j: mp[source])
        {
            if(!visited[j])dfs(mp,visited,j,val,temp);
        }
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> mp;
        for(auto j: edges)
        {
            mp[j[0]].push_back(j[1]);
            mp[j[1]].push_back(j[0]);
        }
        vector<int> visited(n+1,0),colors(n+1,-1);
        for(int node = 1;node <=n;node++){
            if(colors[node]==-1)
        if(!bipartite(mp,node,visited,colors,0))return -1;
        }
        
        vector<int> dist(n+1,0);
        visited.assign(n+1,0);

        for(int node = 1;node <=n;node++)
        {
             dist[node]=bfs(mp,node,n);
        }
       
        int ans = 0;
        for(int node=1;node<=n;node++)
        {
            int val = 0;
            if(!visited[node]){
              dfs(mp,visited,node,val,dist);
              ans+=val;
            }
        }
        return ans;

    }
};