class Solution {
public:
    int mod=1000000007;
    long long solve(string &temp,int index,int k,vector<vector<long long>>&dp){
        if(index>=temp.length())
            return k==2;
        if(dp[index][k]!=-1)
           return dp[index][k];
        if(k==2){
            if(temp[index]=='P'){
        return dp[index][k]=((solve(temp,index+1,0,dp)%mod)+(solve(temp,index+1,k,dp))%mod)%mod;
            }
            else{
                return dp[index][k]= solve(temp,index+1,1,dp)%mod;
            }
        }
        else{
           if(temp[index]=='S')
               return dp[index][k]=solve(temp,index+1,k+1,dp)%mod;
            else
              return dp[index][k]= solve(temp,index+1,k,dp)%mod; 
        }
    }
    int numberOfWays(string corridor) {
        vector<vector<long long>>dp(corridor.length(),vector<long long>(3,-1));
        return solve(corridor,0,0,dp)%mod;
    }
};