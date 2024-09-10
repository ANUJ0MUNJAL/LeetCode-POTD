class Solution {
public:
    void dfs(vector<vector<int>>&grid,int row,int col,int &count)
    {
        if(row < 0 || col < 0 || row >= grid.size() or col>=grid[0].size() or grid[row][col]==0)return;
        grid[row][col]=0;
        count++;
        dfs(grid,row+1,col,count);
        dfs(grid,row,col+1,count);
        dfs(grid,row-1,col,count);
        dfs(grid,row,col-1,count);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
    
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
             for(int j=0;j<grid[i].size();j++)
             {
                 if(grid[i][j])
                 {
                      int count=0;
                     dfs(grid,i,j,count);
                     ans=max(ans,count);
                 }
                     
             }
        }
        return ans;
    }
};