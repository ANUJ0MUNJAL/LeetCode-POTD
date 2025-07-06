class Solution {
public:
    void dfs(int source,map<int,vector<int>>&mp,vector<int>&visited,int count,map<int,set<int>>&par,vector<int>&group)
    {

        visited[source]=1;
        par[count].insert(source);
        group[source]=count;
        for(auto &neigh: mp[source])
        {
            if(!visited[neigh])
               dfs(neigh,mp,visited,count,par,group);
        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        
        map<int,vector<int>> mp;
        for(int i=0;i<connections.size();i++)
        {
            mp[connections[i][0]].push_back(connections[i][1]);
            mp[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int> visited(c+1,0);
        map<int,set<int>> par;
        vector<int> group(c+1,-1);
        int count = 0;
        for(int i=1;i<=c;i++)
        {
            if(!visited[i])
            {
                dfs(i,mp,visited,count,par,group);

            }
            count++;
        }
        // for(auto j: group)cout<<j<<" ";
        vector<int> ans;
        // for(auto j: par)
        // {
        //     cout<<j.first<<"-->";
        //     for(auto i : j.second)
        //     {
        //         cout<<i<<" ";
        //     }
        //     cout<<endl;
        // }
        for(auto j: queries)
        {
            if(j[0] == 1)
            {
                int grp = group[j[1]];
                if(par[grp].size() == 0)
                {
                    ans.push_back(-1);
                }
              else if(par[grp].find(j[1]) != par[grp].end())
               {
                  ans.push_back(j[1]);
               }else{
                  ans.push_back(*par[grp].begin());
               }
            }else{
               int grp = group[j[1]];
               if(par[grp].find(j[1]) != par[grp].end())
               par[grp].erase(par[grp].find(j[1]));
            }
        }
        return ans;

    }
};