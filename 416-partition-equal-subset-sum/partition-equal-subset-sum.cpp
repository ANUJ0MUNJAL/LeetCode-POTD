class Solution {
public:
    
    bool solve(vector<int>&nums,int index,int total,int val,vector<vector<int>>&dp)
    {
        if(index >= nums.size())
        {
             if(val+val == total)return 1;
             return 0;
        }
        if(dp[index][val]!=-1)return dp[index][val];
        int include=0;
        include=solve(nums,index+1,total,val+nums[index],dp);
        int exclude=solve(nums,index+1,total,val,dp);
        return dp[index][val]=include or exclude;
    }
    bool canPartition(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(accumulate(nums.begin(),nums.end(),0)+1,-1));
        return solve(nums,0,accumulate(nums.begin(),nums.end(),0),0,dp);
    }
};