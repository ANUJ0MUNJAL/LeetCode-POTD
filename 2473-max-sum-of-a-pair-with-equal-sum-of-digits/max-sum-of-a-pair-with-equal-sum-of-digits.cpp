class Solution {
public:
    int maximumSum(vector<int>& nums) {
         map<int,vector<int>> mp;
         for(auto j: nums)
         {
              string a = to_string(j);
              int ans=0;
              for(auto i : a)
              {
                   ans+=(i-'0');
              }
              mp[ans].push_back(j);
         }
         int ans=-1;
        
         for(auto j: mp)
         {
              sort(j.second.begin(),j.second.end(),greater<int>());
              if(j.second.size() >= 2)
             {
                 ans=max(ans,j.second[0]+j.second[1]);
             }
         }
         
         return ans;
    }
};