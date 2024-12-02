class Solution {
public:
    int count = 0;
    void dfs(int source,unordered_map<int,vector<int>>&mp,int k,int parent)
    {
        if(k < 0)return;
        count++;
        for(auto neigh: mp[source])
        {
          if(neigh != parent)
            dfs(neigh,mp,k-1,source);
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        vector<int> countfirst(edges1.size()+1,0);
        vector<int> countsecond(edges2.size()+1,0);
        unordered_map<int,vector<int>> mp1,mp2;
        for(int i=0;i<edges1.size();i++)
        {
            mp1[edges1[i][0]].push_back(edges1[i][1]);
            mp1[edges1[i][1]].push_back(edges1[i][0]);
        }
        for(int i=0;i<edges2.size();i++)
        {
            mp2[edges2[i][0]].push_back(edges2[i][1]);
            mp2[edges2[i][1]].push_back(edges2[i][0]);
        }
        for(int i=0;i<=edges1.size();i++)
        {
            dfs(i,mp1,k,-1);
            countfirst[i]=count;
            count=0;
        }
        for(int i=0;i<=edges2.size();i++)
        {
            dfs(i,mp2,k-1,-1);
            countsecond[i]=count;
            count=0;
        }
        sort(countsecond.begin(),countsecond.end());
        vector<int> ans;
        for(int i=0;i<=edges1.size();i++)
        {
            ans.push_back(countfirst[i]+countsecond.back());
        }
        return ans;
      

    }
};