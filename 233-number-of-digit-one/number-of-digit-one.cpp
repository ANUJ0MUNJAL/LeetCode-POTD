class Solution {
public:
    long long dp[11][11][2];
    int solve(int index,string &s,int count,bool flag){
         if(index >= s.length()){
            return count;
         }
         if(dp[index][count][flag]!=-1)return dp[index][count][flag];
         int limit,ans=0;
         if(flag){
            limit=s[index]-'0';
         }else{
             limit=9;
         }
         for(int i=0;i<=limit;i++){
              int total=(i==1) ? count+1: count;
              bool next=(flag and i==limit) ? 1: 0;
              ans+=solve(index+1,s,total,next);
         }
         return dp[index][count][flag]=ans;
    }
    int countDigitOne(int n) {
        string val=to_string(n);
        memset(dp,-1,sizeof(dp));
        return solve(0,val,0,1);
    }
};