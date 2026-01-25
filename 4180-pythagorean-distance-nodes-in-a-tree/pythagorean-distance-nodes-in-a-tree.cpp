class Solution {
public:
    void dfs(int source,unordered_map<int,vector<int>>&mp,vector<int>&dist,vector<int>&vis,int depth)
    {
        vis[source] = 1;
        dist[source] = min(dist[source],depth);
        for(auto neigh: mp[source])
        {
            if(!vis[neigh])
             dfs(neigh,mp,dist,vis,depth+1);
        }
    }
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<int> distx(n,INT_MAX);
        vector<int> disty(n,INT_MAX);
        vector<int> distz(n,INT_MAX);
        unordered_map<int,vector<int>> mp;
        for(auto j: edges)
        {
            mp[j[0]].push_back(j[1]);
            mp[j[1]].push_back(j[0]);
        }
        vector<int> visitedx(n,0);
        dfs(x,mp,distx,visitedx,0);
        vector<int> visitedy(n,0);
        dfs(y,mp,disty,visitedy,0);
        vector<int> visitedz(n,0);
        dfs(z,mp,distz,visitedz,0);

        int count = 0;
        for(int i=0;i<n;i++)
        {
            int a = distx[i];
            int b = disty[i];
            int c = distz[i];
            
            vector<int> temp={a,b,c};
            sort(temp.begin(),temp.end());

            if(pow(temp[0],2) + pow(temp[1],2) == pow(temp[2],2))
            {
                count++;
                

            }



        }
        return count;

    }
};