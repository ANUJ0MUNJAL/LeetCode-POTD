class Solution {
public:
    bool dfs(vector<vector<char>>&grid,int row,int col,int lastrow,int lastcol,char a,vector<vector<bool>>&visited)
    {
         if(row < 0 or col < 0 or row >= grid.size() or col >= grid[0].size() or  grid[row][col]!=a)return false;
         if(visited[row][col] and (lastrow !=row or lastcol != col))
         {
            cout<<row<<" "<<col<<"\n";
          return true;
         }
         visited[row][col]=1;
         bool first=false,second=false,third=false,fourth=false;
        if(row -1 == lastrow and col == lastcol)
        {

        }else
         first = dfs(grid,row-1,col,row,col,a,visited);
        if(row+1 == lastrow and col ==lastcol)
        {

        }else
         second = dfs(grid,row+1,col,row,col,a,visited);
        if(row == lastrow and col+1 == lastcol)
         {

         }else
         third= dfs(grid,row,col+1,row,col,a,visited);
        if(row == lastrow and col-1 == lastcol)
        {

        }else
         fourth = dfs(grid,row,col-1,row,col,a,visited);

         return first or second or third or fourth;


    }
    bool containsCycle(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(!visited[i][j])
                {
                  if(dfs(grid,i,j,i,j,grid[i][j],visited))
                  {
                  
                    return true;
                  }
                }
            }
        }
        return false;

    }
};