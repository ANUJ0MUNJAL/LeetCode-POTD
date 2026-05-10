class Solution {
public:
    int solve(vector<int>&nums,int target,int prev,int index,vector<vector<int>>&dp){
        if(index==nums.size()-1){
            if(abs(nums[index]-nums[prev])<=target)
           return 0;
            return INT_MIN;
        }
        if(index>nums.size())
          return INT_MIN;
        if(dp[index][prev]!=-1)
          return dp[index][prev];
        int include=0;
        int exclude=0;
        if(abs(nums[index]-nums[prev])<=target){
           include=solve(nums,target,index,index+1,dp);
           if(include!=INT_MIN)
             include+=1;
           exclude=solve(nums,target,prev,index+1,dp);
           return dp[index][prev]=max(include,exclude);
        }
        else{
            return dp[index][prev]=solve(nums,target,prev,index+1,dp);
        }
    }
    int maximumJumps(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
        int ans= solve(nums,target,0,1,dp);
        if(ans==INT_MIN)
           return -1;
        else
          return ans+1;
    }
};