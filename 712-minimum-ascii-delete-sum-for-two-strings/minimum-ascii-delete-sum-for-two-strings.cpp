class Solution {
public:
    string ans="";
    int solve(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){
            if(i>=s1.length() && j>=s2.length()){
                  return 0;
            }
            if(i>=s1.length()){
                int sum=0;
                for(int val=j;val<s2.length();val++){
                    sum+=(int)s2[val];
                }
                return sum;
            }
            if(j>=s2.length()){
                 int sum=0;
                for(int val=i;val<s1.length();val++){
                    sum+=(int)s1[val];
                }
                return sum;
            }
            if(dp[i][j]!=-1)
              return dp[i][j];
           
            if(s1[i]==s2[j]){
             return dp[i][j]= solve(s1,s2,i+1,j+1,dp);
            }
            
            else{
    return dp[i][j]=min(s1[i]+solve(s1,s2,i+1,j,dp),s2[j]+solve(s1,s2,i,j+1,dp));
            }
    }
    
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>>dp(s1.length(),vector<int>(s2.length(),-1));
       
       return solve(s1,s2,0,0,dp);
    }
    
};