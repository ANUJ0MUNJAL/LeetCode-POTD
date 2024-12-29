class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int count=0;
         for(int i=0;i<grid[0].size();i++)
         {
            int val = 0;
            for(int j=0;j<grid.size();j++)
            {
                if(j == 0)
                {
                    val = grid[j][i];
                }else{
                     if(grid[j][i] <= grid[j-1][i]){
                        count+=(grid[j-1][i] - grid[j][i]);
                        count++;
                         grid[j][i]=grid[j-1][i]+1;
                     }
                     val=grid[j][i];


                }
            }
            
         }
         return count;
    }
};