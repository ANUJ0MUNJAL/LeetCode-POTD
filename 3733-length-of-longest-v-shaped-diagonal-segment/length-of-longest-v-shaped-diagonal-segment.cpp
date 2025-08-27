class Solution {
public:
    vector<vector<int>> direction = {{1,1},{1,-1},{-1,-1},{-1,1}};
   
    int solve(int row,int col,int k,bool dir,int value,vector<vector<int>>&grid)
    {
          int newrow = row + direction[k][0];
          int newcol = col + direction[k][1];
          int maxi = 0;
          if(newrow >= grid.size() or newcol >= grid[0].size() or newrow < 0 or newcol < 0 or grid[newrow][newcol] != value)
          {
              return 0;
          } 

          int take = 1+solve(newrow,newcol,k,dir,value== 2 ? 0: 2,grid);
          maxi = max(maxi,take);
          int change = 0;
          if(dir == true)
          {
            maxi = max(maxi,1+solve(newrow,newcol,(k+1)%4,false,value == 2 ? 0: 2,grid));
          }
          return maxi;
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                   if(grid[i][j] == 1)
                   {
                        for(int k=0;k<direction.size();k++)
                        {
                            ans = max(ans,1+solve(i,j,k,true,2,grid));
                        }
                   }
            }
        }
        return ans;
    }
};