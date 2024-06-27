class Solution {
public:
    bool check(string &s,int start,int end){
          while(start <= end){
              if(s[start++] != s[end--]) return false;
          }
          return true;
    }
    long long dp[2001];
    int solve(string &s,int index){
        // if(index == s.length()-1) return 0;
        if(index >= s.length()) return -1;
        int ans=INT_MAX;
        int mini=INT_MAX;
        if(dp[index] != -1)return dp[index];
        for(int i=index;i<s.length();i++){
              
              if(check(s,index,i)){
                   ans=1+solve(s,i+1);
              }
              mini=min(mini,ans);
        }
        return dp[index]=mini;
    }
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));

        return solve(s,0);
    }
};