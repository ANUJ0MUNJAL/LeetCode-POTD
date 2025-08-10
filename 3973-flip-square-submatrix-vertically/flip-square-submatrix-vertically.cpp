class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        
        
            int row = x;
            int col = y;

            int endrow = row + k-1;
            int endcol = col + k-1;

            while(row < endrow)
            {
              
                for(int j=col;j<=endcol;j++)
                {
                   
                    swap(grid[row][j],grid[endrow][j]);
                }
                cout<<endl;
                row++;
                endrow--;
            }

        
        return grid;
    }
};