class Solution {
public:
    int solve(int row,int col,int val, vector<vector<int>>&grid,vector<vector<vector<int>>>&dp)
    {
        
        if(row >= grid.size() or col >= grid[0].size())return 1e9;
        val = val ^ grid[row][col];
        if(row == grid.size()-1 and col == grid[0].size()-1)return val;
        if(dp[row][col][val] != -1)return dp[row][col][val];

        return dp[row][col][val] = min(solve(row+1,col,val,grid,dp),solve(row,col+1,val,grid,dp));
        

    }
    int minCost(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(1025,-1)));
        return solve(0,0,0,grid,dp);
    }
};