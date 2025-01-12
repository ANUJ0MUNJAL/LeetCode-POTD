class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
         unordered_map<int,vector<pair<int,int>>> mp;
         for(int i=0;i<edges.size();i++)
         {
            mp[edges[i][1]].push_back({edges[i][0],edges[i][2]});
         }
         vector<int> visited(n,false);
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
         pq.push({0,0});
         visited[0]=true;
         int ans = -1;
         while(!pq.empty())
         {
            int size = pq.size();
            while(size--){
            auto el = pq.top();
            pq.pop();
            if(!visited[el.second])
            ans=max(ans,el.first);
            visited[el.second]=true;
            
            for(auto neigh: mp[el.second])
            {
                 if(!visited[neigh.first])
                 {
                      
                      pq.push({neigh.second,neigh.first});
                 }
            }
            }
         }
         for(auto j: visited)if(j==false)return -1;
         return ans;
    }
};