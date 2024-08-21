class Solution {
public:
    int solve(string &s,int i,int j,vector<vector<int>>&dp){
        if(i==j)
           return 1;
        if(dp[i][j]!=-1)
          return dp[i][j];
        int mini=INT_MAX;
        for(int k=i;k<j;k++){
           mini=min(mini,solve(s,i,k,dp)+solve(s,k+1,j,dp));
        }
        if(s[i]==s[j])
          return dp[i][j]=mini-1;
          return dp[i][j]=mini;
    }
    int strangePrinter(string s) {
        vector<vector<int>>dp(s.length(),vector<int>(s.length(),-1));
        return solve(s,0,s.length()-1,dp);
    }
};