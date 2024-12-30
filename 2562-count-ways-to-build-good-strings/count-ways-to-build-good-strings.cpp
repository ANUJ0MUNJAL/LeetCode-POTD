class Solution {
public:
    long long int mod=1000000007;
    int solve(int update,int low,int high,int addzero, int addone,vector<int>&dp){
        
          if(update>high){
              return 0;
          }
          if(dp[update]!=-1){
              return dp[update];
          }
          if(update>=low && update<=high){
        return dp[update]=(1+solve(update+addzero,low,high,addzero,addone,dp)%mod+solve(update+addone,low,high,addzero,addone,dp)%mod)%mod;
          }
            int totalzero=0,totalone=0;
          if(update+addzero<=high){
             totalzero=solve(update+addzero,low,high,addzero,addone,dp)%mod;
          }
          if(update+addone<=high){
              totalone=solve(update+addone,low,high,addzero,addone,dp)%mod;
          }
          return dp[update]=(totalzero+totalone)%mod;

    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high+1,-1);
        string addzero="";
        string addone="";
        while(zero--){
            addzero.push_back('0');
        }
        while(one--){
            addone.push_back('1');
        }
        string ans="";
        int count=0;
        return solve(0,low,high,addzero.length(),addone.length(),dp);
        return count;
    }
};