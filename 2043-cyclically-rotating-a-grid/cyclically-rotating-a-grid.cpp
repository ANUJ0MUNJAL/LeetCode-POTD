class Solution {
public:
   void rotate(vector<int>& nums, int k) {
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            ans[(i+k)%nums.size()]=nums[i];
        }
       nums=ans;
    }

    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
       vector<vector<int>> ans;

       for(int i=0;i<min(grid.size(), grid[0].size())/2;i++)
       {
          vector<int> temp;

          for(int j=i;j<grid.size()-i;j++)
          {
              temp.push_back(grid[j][i]);
          }

          for(int j=i+1;j<grid[0].size()-i;j++)
          {
              temp.push_back(grid[grid.size()-i-1][j]);
          }

          for(int j=grid.size()-i-2;j>=i;j--)
          {
              temp.push_back(grid[j][grid[0].size()-i-1]);
          }

          for(int j=grid[0].size()-i-2;j>i;j--)
          {
            temp.push_back(grid[i][j]);
          }

          rotate(temp,k);

          int idx = 0;

        
          for(int j=i;j<grid.size()-i;j++)
          {
              grid[j][i] = temp[idx++];
          }

          for(int j=i+1;j<grid[0].size()-i;j++)
          {
             grid[grid.size()-i-1][j] = temp[idx++];
          }

     
          for(int j=grid.size()-i-2;j>=i;j--)
          {
            grid[j][grid[0].size()-i-1] = temp[idx++];
          }

          for(int j=grid[0].size()-i-2;j>i;j--)
          {
            grid[i][j] = temp[idx++];
          }

       }         
       return grid;                                                
    }
};