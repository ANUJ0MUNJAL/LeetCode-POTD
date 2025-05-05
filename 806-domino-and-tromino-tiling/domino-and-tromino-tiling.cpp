class Solution {
public:
    int dp[1001];
    int mod=1e9+7;
    int numTilings(int n) {
        if(n==1 or n==2)
           return n;
        memset(dp,0,sizeof(dp));

        dp[1]=1;
        dp[2]=2;
        dp[3]=5;
        for(int i=4;i<=n;i++){
            dp[i]=(2*dp[i-1] %mod + dp[i-3] %mod)%mod;
        }
        return dp[n];
    }
};