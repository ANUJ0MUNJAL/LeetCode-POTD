class Solution {
public:
    bool check(int row,int col,vector<vector<int>>&grid)
    {
        if(row+2 >= grid.size() || col+2 >= grid[0].size())return 0;
        set<int> st;
        map<int,int> mp;
        for(int i=row;i<row+3;i++)
        {
            int sum=0;
            for(int j=col;j<col+3;j++)
            {
                  if(grid[i][j]==0)return 0;
                  if(grid[i][j] > 9)return 0;
                  if(mp.find(grid[i][j])!=mp.end())return 0;
                  mp[grid[i][j]]++;
                  sum+=grid[i][j];
            }
            st.insert(sum);
        }
        mp.clear();
        if(st.size()>1)return 0;

        for(int i=col;i<col+3;i++)
        {
            int sum=0;
            for(int j=row;j<row+3;j++)
            {
                  if(mp.find(grid[j][i])!=mp.end())return 0;
                    mp[grid[j][i]]++;
                  if(grid[j][i] > 9)return 0;
                  sum+=grid[j][i];
            }
            st.insert(sum);
        }
         mp.clear();
         if(st.size()>1)return 0;
         int j=col;
         int sum=0;
         for(int i=row;i<row+3;i++){
             if(mp.find(grid[i][j])!=mp.end())return 0;
                  mp[grid[i][j]]++;
             sum+=grid[i][j];
             j++;
         }
         mp.clear();
         st.insert(sum);
         j=col+2;
         sum=0;
         for(int i=row;i<row+3;i++)
         {
             if(mp.find(grid[i][j])!=mp.end())return 0;
                  mp[grid[i][j]]++;
            sum+=grid[i][j];
            j--;
         }
         st.insert(sum);

         return st.size()==1;

    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                ans+=check(i,j,grid);
            }
        }
        return ans;
    }
};