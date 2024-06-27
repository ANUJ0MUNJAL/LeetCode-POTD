class Solution {
public:
    int rob(vector<int>& nums) {
         map<int,int> dp;
         if(nums.size() == 1){
            return nums[0];
         }
         int maxi=0;
         for(int i=1;i<nums.size();i++){
              dp[i]=max({dp[i],dp[i-1],dp[i-2]+nums[i]});
              
              maxi=max(maxi,dp[i]);
         }
           dp.clear();
          for(int i=0;i<nums.size()-1;i++){
              dp[i]=max({dp[i],dp[i-1],dp[i-2]+nums[i]});
              maxi=max(maxi,dp[i]);
         }
         return maxi;
    }
};