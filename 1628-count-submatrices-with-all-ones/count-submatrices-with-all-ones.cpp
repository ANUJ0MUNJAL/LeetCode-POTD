class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
          
          for(int i=0;i<mat.size();i++)
          {
            for(int j=mat[i].size()-2;j>=0;j--)
            {
                  if(mat[i][j])
                  {
                     mat[i][j]+=mat[i][j+1];
                  }
            }
          }
          int ans=0;
          for(int i=0;i<mat.size();i++)
          {
                for(int j=0;j<mat[i].size();j++)
                {
                       
                       int mini=mat[i][j];
                       for(int k=i;k<mat.size();k++)
                       {
                             if(mat[k][j] == 0)break;
                             mini=min(mini,mat[k][j]);
                             ans+=mini;
                       }
                }
          }
          return ans;
    }
};