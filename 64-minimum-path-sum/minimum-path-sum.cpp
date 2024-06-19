class Solution {
public:
    int solve(vector<vector<int>>&grid,int row,int col,vector<vector<int>>&dp){
        if(row==grid.size()-1 && col==grid[0].size()-1){
            return dp[row][col]=grid[row][col];
        }
        if(row>=grid.size() || col >=grid[0].size()){
            return INT_MAX;
        }
        if(dp[row][col]!=-1)
           return dp[row][col];
        int include=INT_MAX;
        int exclude=INT_MAX;
        if(col+1<grid[0].size()){
           include=solve(grid,row,col+1,dp);
        }

        if(row+1<grid.size()){
            exclude=solve(grid,row+1,col,dp);
        }
        return dp[row][col]=min(include,exclude)+grid[row][col];
    }
    int minPathSum(vector<vector<int>>& grid) {
vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),0));
       
        // return solve(grid,0,0,dp);
        dp[grid.size()-1][grid[0].size()-1]=grid[grid.size()-1][grid[0].size()-1];
        for(int i=grid.size()-1 ; i>=0 ;i--){
              for(int j=grid[0].size()-1;j>=0;j--){
                   int inc=INT_MAX,exc=INT_MAX;
                   if(j+1 < grid[0].size()){
                        inc=dp[i][j+1];
                   }
                   if(i+1 < grid.size()){
                       exc=dp[i+1][j];
                   }
                
                   int val = min(inc,exc);
                   if(val != INT_MAX){
                      dp[i][j]=grid[i][j]+val;
                   }
              }
        }
        return dp[0][0];
    }
};