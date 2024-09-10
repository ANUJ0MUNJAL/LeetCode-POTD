class Solution {
public:
    long long dp[501][501];
    int solve(string&a,string&b,int i,int j)
    {
        if(i >= a.length() || j >= b.length())
        {
           return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(a[i] == b[j])
        {
             return 1+solve(a,b,i+1,j+1);
        }
        return dp[i][j]=max(solve(a,b,i+1,j),solve(a,b,i,j+1));
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return word1.length()+word2.length()-2*solve(word1,word2,0,0);
    }
};