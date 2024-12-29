#define MOD 1000000007
class Solution {
public:
  long solve(int i,int j,vector<string>&words,string target,vector<vector<int>>&freq,vector<vector<long long>>&dp){
              
               if(j==target.length())
                  return 1;
                if(i>=words[0].length()|| words[0].size() - i < target.size() - j){
                    return 0;
                }
                if(dp[i][j]!=-1)
                  return dp[i][j];
                long long res=0;
                int curr=target[j]-'a';
                 res+=1LL*solve(i+1,j,words,target,freq,dp)%MOD; 
                res+=1LL*((freq[i][curr]%MOD)*(solve(i+1,j+1,words,target,freq,dp)%MOD))%MOD;
               
                return dp[i][j]=res%1000000007;

    }
    int numWays(vector<string>& words, string target) {
        vector<vector<int>>freq(words[0].length(),vector<int>(26,0));
        vector<vector<long long>>dp(words[0].length(),vector<long long>(target.length(),-1));
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[0].length();j++){
                char ans=words[i][j];
                freq[j][ans-'a']++;
            }
        }
        string ans="";
        return solve(0,0,words,target,freq,dp);


    }
};