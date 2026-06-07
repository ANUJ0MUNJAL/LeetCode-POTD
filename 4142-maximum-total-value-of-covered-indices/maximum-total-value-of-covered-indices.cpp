class Solution {
public:
    long long dp[100001][2];
    long long solve(vector<int>&nums,string &s,int index,bool flag)
    {
        if(index >= s.length())return 0;

        if(dp[index][flag]!=-1)return dp[index][flag];

        long long include = 0;
        long long another = 0;
        if(s[index] == '1')
        {
             include = nums[index] + solve(nums,s,index+1,1);

            if(index-1 >= 0 and !flag)
            {
                another = nums[index-1] + solve(nums,s,index+1,0);
            }
            
        }else{
            another = solve(nums,s,index+1,0);
        }
        return dp[index][flag] = max(include,another);
    }
    long long maxTotal(vector<int>& nums, string s) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,s,0,0);
    }
};