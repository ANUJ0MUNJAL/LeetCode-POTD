class Solution {
public:
    int solve(string &s,unordered_map<string,int>&mp,int prev,int index,vector<vector<int>>&dp){
        if(index>=s.length()){
             
            if(mp.find(s.substr(prev,index-prev))!=mp.end()){
                return index-prev;
            }
            return 0;
        }
        if(dp[prev][index]!=-1)
          return dp[prev][index];
        
        int include=0;
        if(mp.find(s.substr(prev,index-prev+1))!=mp.end()){
          
          include=index-prev+1+solve(s,mp,index+1,index+1,dp);
        }
      
        int exclude=max(solve(s,mp,prev,index+1,dp), solve(s,mp,prev+1,index+1,dp));
        return dp[prev][index]=max(include,exclude);

    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string,int> mp;
        for(auto j: dictionary){
            mp[j]=1;
        }
        vector<vector<int>>dp(s.length(),vector<int>(s.length(),-1));
        return s.length()-solve(s,mp,0,0,dp);
    }
};