class Solution {
public:
    int ans = 0;
    long long dfs(int source,unordered_map<int,vector<int>>&mp,int sum,vector<int>&arr,int k,vector<int>&visited)
    {
        if(mp[source].size()==0)return 0;
        long long val=0;
        visited[source]=1;
        for(auto neigh: mp[source])
        {
            if(!visited[neigh])
             val+=dfs(neigh,mp,sum,arr,k,visited);
        }
        val+=arr[source];
        // cout<<source<<" "<<val<<endl;
        if(val % k == 0)ans++;
        return val;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        unordered_map<int,vector<int>> mp;
        for(auto j: edges)
        {
            mp[j[0]].push_back(j[1]);
            mp[j[1]].push_back(j[0]);
        }
        vector<int> visited(n,false);
        dfs(0,mp,0,values,k,visited);
        if(ans == 0)return 1;
        return ans;
    }
};