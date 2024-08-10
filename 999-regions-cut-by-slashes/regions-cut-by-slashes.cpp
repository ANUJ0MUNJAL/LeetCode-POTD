class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&region)
    {
        if(row < 0 || col < 0 || row >= region.size() || col >= region.size() || region[row][col]==1)return;
        region[row][col]=1;
         dfs(row+1,col,region);
         dfs(row,col+1,region);
         dfs(row,col-1,region);
         dfs(row-1,col,region);
    }
    int regionsBySlashes(vector<string>& grid) {
         vector<vector<int>>region(grid.size()*3,vector<int>(grid.size()*3,0));

          for(int i=0;i<grid.size();i++)
          {
            for(int j=0;j<grid.size();j++)
            {
                 if(grid[i][j]=='/')
                 {
                     region[i*3][3*j+2]=1;
                     region[i*3+1][3*j+1]=1;
                     region[i*3+2][3*j]=1;
                 }
                 if(grid[i][j]=='\\')
                 {
                     region[3*i][3*j]=1;
                     region[3*i+1][3*j+1]=1;
                     region[3*i+2][3*j+2]=1;
                 }
            }
          }
          int count=0;
          for(int i=0;i<region.size();i++)
          {
            for(int j=0;j<region.size();j++)
            {
                if(region[i][j]==0)
                {
                      dfs(i,j,region);
                      count++;
                }
            }
          }
          return count;
    }
};
