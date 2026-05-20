class Solution {
public:
    long long dp[501][501][2];
    int mod = 1000000007;
    long long solve(vector<vector<int>>&grid,int row,int col,int flag)
    {
        if(row >= grid.size() or col >= grid[0].size())return 0;
        if(row == grid.size()-1 and col == grid[0].size()-1)return 1;

        if(dp[row][col][flag] != -1)
        {
            return dp[row][col][flag];
        }
        
        long long ans = 0;
        if(grid[row][col] == 1)
        {
            if(flag)
            {
               ans = (ans%mod +  solve(grid,row+1,col,0)%mod)%mod;
            }else{
               ans = (ans%mod + solve(grid,row,col+1,1)%mod)%mod;
            }

        }else{
            ans = (ans%mod +  (solve(grid,row+1,col,0) % mod +solve(grid,row,col+1,1) % mod)%mod)%mod;
        }
        return dp[row][col][flag] = ans % mod;

    }
    int uniquePaths(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return (solve(grid,0,1,1)%mod + solve(grid,1,0,0)%mod)%mod;
    }
};