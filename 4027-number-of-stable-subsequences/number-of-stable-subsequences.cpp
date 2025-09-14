class Solution {
public:
    long long dp[100005][4][4];
    int mod = 1e9+7;
    long long solve(vector<int>&nums,int index,int first,int second)
    {
        if(index >= nums.size())return 0;
        if(dp[index][first+1][second+1] != -1)
        {
            return dp[index][first+1][second+1];
        }
        long long include = 0;
        if(first == -1)
        {
           include =  1 + solve(nums,index+1,nums[index] % 2, second);
        }else if(second == -1)
        {
          include =  1 + solve(nums,index+1,first,nums[index]%2);
        }else{
            if(first == second)
            {
                if(nums[index] % 2 != second)
                {
                    include = 1 + solve(nums,index+1,second,nums[index]%2);
                }
            }else{
                include = 1 + solve(nums,index+1,second,nums[index]%2);
            }
        }
        long long exclude = solve(nums,index+1,first,second);

        return dp[index][first+1][second+1] = (include%mod + exclude%mod)%mod;

         
    }
    int countStableSubsequences(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,-1,-1);
    }
};