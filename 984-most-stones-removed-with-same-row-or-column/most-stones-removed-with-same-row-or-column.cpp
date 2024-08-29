class Solution {
public:
    int maxi=1;
    void dfs(int source,map<int,vector<int>>&mp,vector<int>&visited,vector<int> &parent)
    {
        parent[source]=maxi;
        visited[source]=1;
    
        
        for(auto j: mp[source])
        {
            if(!visited[j])
            {
                 dfs(j,mp,visited,parent);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        map<int,vector<int>> mp;
        vector<int> parent(stones.size());

        for(int i=0;i<stones.size();i++)
        {
              parent[i]=i;
              for(int j=0;j<stones.size();j++)
              {
                  if(i == j)continue;
                  if(stones[j][0] == stones[i][0] or stones[j][1]==stones[i][1])mp[i].push_back(j);
              }

        }
        vector<int> visited(stones.size(),false);
        for(int i=0;i<stones.size();i++)
        {
              if(!visited[i])
              {
                  dfs(i,mp,visited,parent);
                  maxi++;
              }
        }
        map<int,int> m;
        int ans=0;
        for(int i=0;i<stones.size();i++)
        {
             m[parent[i]]++;  
        }
        for(auto j: m)
        {
             ans+=j.second-1;
        }
        return ans;


        
       
    }
};

