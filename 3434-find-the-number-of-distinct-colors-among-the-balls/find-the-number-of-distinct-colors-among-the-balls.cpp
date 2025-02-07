class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int,int> mp1,mp2;
        
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
           if(mp2.find(queries[i][0])!=mp2.end()){
               mp1[mp2[queries[i][0]]]--;
               if(mp1[mp2[queries[i][0]]]==0){
                   mp1.erase(mp2[queries[i][0]]);
               }
           }
            mp1[queries[i][1]]++;
            mp2[queries[i][0]]=queries[i][1];
            ans.push_back(mp1.size());
        }
        return ans;
    }
};