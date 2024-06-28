class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
         vector<int> degree(n,0);
         for(auto j: roads){
              degree[j[0]]++;
              degree[j[1]]++;
         }
         
         set<pair<int,int>> st;
         for(int i=0;i<degree.size();i++){
            st.insert({degree[i],i});
         }
         vector<int> nums(n,0);
         int val=1;
         for(auto &j: st){
               auto itr=st.begin();
               nums[itr->second]=val;
               st.erase(st.begin());
               val++;
         }
         long long sum=0;
       
         for(auto &j: roads){
               sum+=nums[j[0]];
               sum+=nums[j[1]];
         }
         return sum;

    }
};