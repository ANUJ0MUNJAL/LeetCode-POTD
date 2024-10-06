class Solution {
public:
   void dfs(int source,map<int,vector<int>>&mp,vector<int>&visited)
  {
       visited[source]=1;
       for(auto j: mp[source])
       {
            if(!visited[j])dfs(j,mp,visited);
       }
  }
  bool answer=false;
   void dfs1(int source,map<int,vector<int>>&mp,vector<int>&another,vector<int>&visited)
   {
         another[source]=1;
         if(visited[source]==1)
         {
            answer=true;
            return;
         }
         for(auto j: mp[source])
         {
            if(!another[j])dfs1(j,mp,another,visited);
         } 
   }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        map<int,vector<int>> mp;
        for(int i=0;i<invocations.size();i++)
        {
            mp[invocations[i][0]].push_back(invocations[i][1]);
        }
        vector<int> visited(n,false);
        dfs(k,mp,visited);
        vector<int> another(n,false);
        vector<int> ans;
        for(int i=0;i<n;i++)ans.push_back(i);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs1(i,mp,another,visited);
                if(answer)return ans;
            }
        }
        vector<int> temp;
        for(int i=0;i<visited.size();i++)
        {
            if(!visited[i])temp.push_back(i);
        }
        return temp;
    }
};