class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&temp)
    {
        if(row < 0 or col < 0 or row >= temp.size() or col >= temp[0].size() or temp[row][col]==0)return;
        temp[row][col]=0;
        dfs(row+1,col,temp);
        dfs(row-1,col,temp);
        dfs(row,col+1,temp);
        dfs(row,col-1,temp);
    }
    int solve(vector<vector<int>> temp)
    {
        int count=0;
        for(int i=0;i<temp.size();i++)
        {
            for(int j=0;j<temp[0].size();j++)
            {
                if(temp[i][j]){
                      dfs(i,j,temp);
                      count++;
                }
            }
        }
     
        return count;
    }
    int minDays(vector<vector<int>>& grid) {
        
        vector<vector<int>> temp=grid;
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(temp[i][j])
                {
                    dfs(i,j,temp);
                    count++;
                }
            }
        }
        if(count>1 or count==0)return 0;
        temp=grid;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                
                  if(temp[i][j])
                  {
                    
                      temp[i][j]=0;
                      if(solve(temp)!=1)return 1;
                      temp[i][j]=1;
                  }
            }
          
        }
        return 2;

    }
};