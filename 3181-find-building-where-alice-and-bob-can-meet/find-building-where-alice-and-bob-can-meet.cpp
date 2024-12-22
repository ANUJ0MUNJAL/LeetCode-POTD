class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(),-1);
        map<int,vector<pair<int,int>>> mp;
        for(int i=0;i<queries.size();i++){
            int u=queries[i][0];
            int v=queries[i][1];
            
            if(u<v && heights[v]>heights[u])
                ans[i]=v;
            else if(v<u && heights[u]>heights[v])
                ans[i]=u;
            else if(v==u && heights[u]==heights[v])
                ans[i]=u;
            else{
                mp[{max(u,v)}].push_back({max(heights[u],heights[v]),i});
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<heights.size();i++){
            while(!pq.empty() && pq.top().first<heights[i]){
                ans[pq.top().second]=i;
                pq.pop();
            }
            
            for(auto j: mp[i]){
                pq.push(j);
            }
        }
        return ans;
    }
};