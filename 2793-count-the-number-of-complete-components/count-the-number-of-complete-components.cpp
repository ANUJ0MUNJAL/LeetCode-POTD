class Solution {
public:
    void dfs(vector<int>&visited,int source,unordered_map<int,vector<int>>&mp,set<int>&st)
    {
          visited[source]=1;
          st.insert(source);

          for(auto neigh: mp[source])
          {
              if(!visited[neigh])
              {
                   dfs(visited,neigh,mp,st);
              }
          }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
           unordered_map<int,vector<int>> mp;
           vector<int> visited(n,false);
           int ans = 0;

           for(int i=0;i<edges.size();i++)
           {
               mp[edges[i][0]].push_back(edges[i][1]);
               mp[edges[i][1]].push_back(edges[i][0]);
           }

           for(int i=0;i<n;i++)
           {
               if(!visited[i])
               {
                   set<int> st;
                   dfs(visited,i,mp,st);
                   int count = 0;
                   for(int j=0;j<edges.size();j++)
                   {
                        int u = edges[j][0];
                        int v = edges[j][1];

                        if(st.find(u) != st.end() && st.find(v) != st.end())
                        {
                              count++;
                        }
                   }

                   if(count == (st.size()*(st.size()-1))/2)ans++;
               }
           }
           return ans;
    }
};