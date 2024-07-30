class Solution {
public:
    long long dp[100001][2];
    int solve(string &s,int index,bool flag){
        if(index >= s.length())return 0;
        if(dp[index][flag]!=-1)return dp[index][flag];
        int include=INT_MAX;
        if(flag){
              if(s[index]=='a'){
                   include=1+solve(s,index+1,flag);
                   return dp[index][flag]=include;
              }else{
                return dp[index][flag]=solve(s,index+1,flag);
              }
        }else{
            if(s[index]=='b'){
            int include=1+solve(s,index+1,flag);
            int exclude=solve(s,index+1,1);
            return dp[index][flag]=min(include,exclude);
            }else{
                return dp[index][flag]=solve(s,index+1,flag);
            }
        }
      

    }
    int minimumDeletions(string s) {
        memset(dp,-1,sizeof(dp));
       return solve(s,0,0);
    }
};