class Solution {
public:
    long long dp[1001][1001];
    int solve(int n,int count,int prev)
    {
        if(count > n)return 1e7;
        if(count == n)return 0;
        if(dp[count][prev]!=-1)return dp[count][prev];
        int include=1e7,exclude=1e7;
        if(prev!=0 and count+prev <= n)
        {
            include=1+solve(n,count+prev,prev);
        }
       if(prev != count)
        exclude=1+solve(n,count,count);
        return dp[count][prev]=min(include,exclude);
    }
    int minSteps(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n,1,0);
    }
};