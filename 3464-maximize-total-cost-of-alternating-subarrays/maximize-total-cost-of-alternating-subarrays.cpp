class Solution {
public:
    long long dp[100001][2];
    long long solve(vector<int>&nums,int index,int prev){
         if(index >= nums.size())return 0;
         if(dp[index][prev]!=-1)return dp[index][prev];
        long long include=0;
        
        if(prev == 0){
            include=nums[index]+solve(nums,index+1,1);
        }else{
            include=-1*nums[index]+solve(nums,index+1,0);
        }
        long long exclude=nums[index]+solve(nums,index+1,1);
        return dp[index][prev]=max(include,exclude);
    }
    long long maximumTotalCost(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,0);
    }
};