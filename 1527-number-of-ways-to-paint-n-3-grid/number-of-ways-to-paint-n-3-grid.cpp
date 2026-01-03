class Solution {
public:
    vector<vector<int>> perm = {{0,1,2},{1,2,0},{0,2,1},{1,0,2},{2,0,1},{2,1,0},{1,0,1},{1,2,1},{2,0,2},{2,1,2},{0,1,0},{0,2,0}};
    int mod  = 1e9+7;
    long long dp[5001][4][4][4];
    int solve(int n,int first,int second,int third, int index)
    {
      if(index >= n)return 1;
      if(dp[index][first+1][second+1][third+1]!=-1)return dp[index][first+1][second+1][third+1];
      int ans = 0;
      for(int i=0;i<perm.size();i++)
        {
            int a = perm[i][0];
            int b = perm[i][1];
            int c = perm[i][2];

            if((first!=a and second!=b and third!=c))
            {
                ans = (ans%mod + solve(n,a,b,c,index+1)%mod)%mod;
            }
        }
        return dp[index][first+1][second+1][third+1] =  ans;
    }
    int numOfWays(int n) {
       memset(dp,-1,sizeof(dp));
       return solve(n,-1,-1,-1,0);
    }
};