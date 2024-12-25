class Solution {
public:
    long long dp[301][301][17];
    long long mod = 1e9+7;
    long long solve(vector<vector<int>>&grid,int row,int col,int k,int val)
    {
        if(row == grid.size()-1 and col == grid[0].size()-1)
        {
            if((val ^ grid[row][col]) == k)return 1;
            return 0;
        }
        if(dp[row][col][val]!=-1)return dp[row][col][val];
        long long first=0,second=0;
        if(row+1 < grid.size())
        {
            first=solve(grid,row+1,col,k,val ^ grid[row][col]);
        }
        if(col+1 < grid[0].size())
        {
            second=solve(grid,row,col+1,k,val^grid[row][col]);
             
        }
        return dp[row][col][val]=(first%mod+second%mod)%mod;
    }
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(grid,0,0,k,0);
    }
};