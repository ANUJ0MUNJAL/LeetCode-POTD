class Solution {
public:
    int mod=1000000007;
    long long solve(int n,int delay,int forget,vector<long long>&dp){
        if(n==0)
            return 0;
        if(dp[n]!=-1)
           return dp[n];
        long long ans=1;
        for(int i=delay;i<forget;i++){
              if(n-i>=0)
               ans=ans+solve(n-i,delay,forget,dp)%mod;
        }
        return dp[n]=ans%mod;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(n+1,-1);
        return (solve(n,delay,forget,dp)-solve(n-forget,delay,forget,dp)+mod)%mod;
    }
};