class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<set<int>> ans(n);
        unordered_map<int,vector<int>> mp;
        vector<int> indegree(n,0);
        for(int i=0;i<edges.size();i++){
             mp[edges[i][0]].push_back(edges[i][1]);
             indegree[edges[i][1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
             if(indegree[i] == 0){
                 q.push(i);
               
             }
        }
        while(!q.empty()){
            auto el=q.front();
            q.pop();

            for(auto &neigh: mp[el]){
                  indegree[neigh]--;
                  
                  ans[neigh].insert(el);
                  for(auto j: ans[el]){
                     ans[neigh].insert(j);
                  }
                  if(indegree[neigh] == 0){
                     q.push(neigh);
                  }
            }
        }
        vector<vector<int>> temp;
        for(auto j :ans){
            vector<int> val;
             for(auto i :j){
                  val.push_back(i);
             }
             temp.push_back(val);
        }
        return temp;
        
    }
};