class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
         int row1=grid.size(),row2=0,col1=grid[0].size(),col2=0;
         for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
              if(grid[i][j] == 1){
                  row1=min(row1,i);
                  col1=min(col1,j);
                  row2=max(row2,i);
                  col2=max(col2,j);
                  
              }
            }
         }
         
         return (row2-row1+1)*(col2-col1+1);
    }
};