class Solution {
public:
   long long dp[21][5000];
    int solve(vector<int>&nums,int target,int index){
        if(index >= nums.size()){
            if(target==0)return 1;
            return 0;
        }
        
        if(dp[index][target+1000]!=-1)return dp[index][target+1000];
        int include=0,exclude=0;
        include=solve(nums,target+nums[index],index+1);
        exclude=solve(nums,target-nums[index],index+1);
        return dp[index][target+1000]=include+exclude;
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,target,0);
    }
};