class Solution {
public:
    void dfs(vector<vector<int>>&grid,int row,int col,int &count,vector<vector<int>>&visited)
    {
        if(row < 0 or col < 0 or row >= grid.size() or col >= grid[0].size() or visited[row][col] or grid[row][col] == 0)return;
        visited[row][col]=1;
        count+=grid[row][col];
        dfs(grid,row+1,col,count,visited);
        dfs(grid,row,col+1,count,visited);
        dfs(grid,row-1,col,count,visited);
        dfs(grid,row,col-1,count,visited);
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int ans = 0;
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),false));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(!visited[i][j] and grid[i][j]>0)
                {
                    int count = 0;
                    dfs(grid,i,j,count,visited);
                    ans = max(ans,count);
                }
            }
        }
        return ans;
    }
};