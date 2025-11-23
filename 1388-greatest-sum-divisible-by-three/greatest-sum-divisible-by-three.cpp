class Solution {
public:
    long long dp[100001][4];
    int solve(vector<int>&nums,int index,int value)
    {
        if(index >= nums.size())
        {
            if(value == 0)return 0;
            return -1e7;
        }
        if(dp[index][value] != -1)return dp[index][value];
        int include = 0;
        include = nums[index] + solve(nums,index+1,(nums[index] + value)%3);
        int exclude = solve(nums,index+1,value);

        return dp[index][value] = max(include,exclude);
    }
    int maxSumDivThree(vector<int>& nums) {
             memset(dp,-1,sizeof(dp));
             return solve(nums,0,0);

    }
};