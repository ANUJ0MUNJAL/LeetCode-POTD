class Solution {
public:
    int ans=INT_MIN;
    int dfs(vector<vector<int>>&grid,int row,int col,vector<vector<int>>&dp)
    {
        if(dp[row][col]!=-1)return dp[row][col];
        int count=0;
        if(row+1 < grid.size() and col+1<grid[0].size() and grid[row][col] < grid[row+1][col+1])
          count=max(count,1+dfs(grid,row+1,col+1,dp));
        if(row-1>=0 and col+1 < grid[0].size() and grid[row][col] < grid[row-1][col+1])
          count=max(count,1+dfs(grid,row-1,col+1,dp));
        if(col+1 < grid[0].size() and grid[row][col] < grid[row][col+1])
           count=max(count,1+dfs(grid,row,col+1,dp));
        return dp[row][col]=count;
        
    }
    int maxMoves(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
         for(int i=0;i<grid.size();i++)
         {
              ans=max(ans,dfs(grid,i,0,dp));
         }
         return ans;
    }
};