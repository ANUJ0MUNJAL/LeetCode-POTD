class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& matrix) {
         vector<pair<int,int>> arr[201];
         for(int i=0;i<matrix.size();i++)
         {
            for(int j=0;j<matrix[0].size();j++)
            {
                arr[matrix[i][j]].push_back({i,j});
            }
         }

         int ans = 0;
         for(int i=0;i<matrix.size();i++)
         {
            for(int j=0;j<matrix[0].size();j++)
            {
                int val = matrix[i][j];

                if(val == 0)continue;

                bool flag = true;

                for(int k = val+1;k <= 200 and flag;k++)
                {
                     
                      for(auto&[r,c] : arr[k])
                      {
                          int rd = abs(r-i);
                          int cd = abs(c-j);

                          if(rd <= val and cd <= val)
                          {
                                if(rd == val and cd == val)continue;
                                flag = false;
                                break;
                          }
                      }
                }
                ans += flag;
            }
         }
         return ans;
    }
};