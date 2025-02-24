class Solution {
public:
    map<int,int> time,another;
    void dfs(int source,unordered_map<int,vector<int>>&mp,int parent,int count)
    {
         if(source == 0)
         {
            time[source]=count;

            another = time;
            return;
         }
         time[source]=count;
         for(auto &neigh: mp[source])
         {
              if(neigh != parent)
              {
                  dfs(neigh,mp,source,count+1);
              }
         }
         time.erase(source);
    }
    int maxi = INT_MIN;
    void solve(int source,unordered_map<int,vector<int>>&mp,int count ,int parent,vector<int>&amount,int time1)
    {
                int val = 0;
             if(another.count(source)){
                if(another[source] < time1)
                {
                   val = 0;
                }else if(another[source] > time1)
                {
                   val = amount[source];
                }else{
                   val = amount[source]/2;
                }
             }else{
                val = amount[source];
             }

          
        if(mp[source].size() == 1 and source != 0)
        {
              

            maxi=max(maxi,count+val);
            return;
        }
        
        for(auto neigh: mp[source])
        {
            if(neigh != parent)
            {
                

                solve(neigh,mp,count+val,source,amount,time1+1);
            }
        }
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
           unordered_map<int,vector<int>> mp;
           for(int i=0;i<edges.size();i++)
           {
               mp[edges[i][0]].push_back(edges[i][1]);
               mp[edges[i][1]].push_back(edges[i][0]);
           }
           dfs(bob,mp,-1,0);
           


           solve(0,mp,0,-1,amount,0);
           return maxi;
    }
};