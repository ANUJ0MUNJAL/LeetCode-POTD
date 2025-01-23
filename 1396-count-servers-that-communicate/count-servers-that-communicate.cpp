class Solution {
public:
    bool check(int row,int col,vector<vector<int>>&grid)
    {
          int i = row-1;
          while(i >= 0)
          {
              if(grid[i][col])return true;
              i--;
          }
          i = row+1;
          while(i < grid.size())
          {
            if(grid[i][col])return true;
            i++;
          }
          int j = col-1;
          while(j >= 0)
          {
            if(grid[row][j])return true;
            j--;
          }
          j = col+1;
          while(j < grid[0].size())
          {
              if(grid[row][j])return true;
              j++;
          }
          return false;
    }
    int countServers(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),false));
        int ans = 0;
        int count =0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                  if(grid[i][j] == 1)
                  {
                     if(check(i,j,grid))
                      count++;
                  }
            }
        }
        
        return count;
    }
};