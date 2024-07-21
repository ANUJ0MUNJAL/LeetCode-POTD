class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
         unordered_map<int,vector<int>> mp;
         vector<int> indegree(k,0);
         vector<vector<int>> uttar;
         for(int i=0;i<rowConditions.size();i++){
            mp[rowConditions[i][0]].push_back(rowConditions[i][1]);
            indegree[rowConditions[i][1]-1]++;
         }
         queue<int> q;
         for(int i=0;i<indegree.size();i++){
             if(indegree[i] == 0){
                q.push(i+1);
             }
         }
         vector<int> ans;
         while(!q.empty()){
             auto el=q.front();
             q.pop();
             ans.push_back(el);
             for(auto &neigh: mp[el]){
                  indegree[neigh-1]--;
                  if(indegree[neigh-1] == 0){
                      q.push(neigh);
                  }
             }
         }
         if(ans.size() != k)return uttar;
         mp.clear();
         indegree.resize(k,0);

        for(int i=0;i<colConditions.size();i++){
            mp[colConditions[i][0]].push_back(colConditions[i][1]);
            indegree[colConditions[i][1]-1]++;
         }
      
         for(int i=0;i<indegree.size();i++){
             if(indegree[i] == 0){
                q.push(i+1);
             }
         }
         vector<int> ans1;
         while(!q.empty()){
             auto el=q.front();
             q.pop();
             ans1.push_back(el);
             for(auto &neigh: mp[el]){
                  indegree[neigh-1]--;
                  if(indegree[neigh-1] == 0){
                      q.push(neigh);
                  }
             }
         }
         if(ans1.size()!=k)return uttar;
         uttar.resize(k,vector<int>(k,0));
         for(int i=0;i<ans.size();i++){
              int val=ans[i];
              int index=0;
              for(int j=0;j<ans1.size();j++){
                   if(ans1[j] == val){
                         index=j;
                         break;
                   }
              }
              uttar[i][index]=ans[i];
         }
         return uttar;

         

    }
};