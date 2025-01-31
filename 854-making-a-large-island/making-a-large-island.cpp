class Solution {
public:
     map<pair<int,int>,pair<int,int>> mp;
    void dfs(int row,int col,int parrow,int parcol,vector<vector<int>>&visited,vector<vector<int>>&grid,int &count)
    {
        if(row < 0 or col < 0 or row >=grid.size() or col >= grid[0].size() or visited[row][col] or !grid[row][col])return;
        mp[{row,col}]={parrow,parcol};
        visited[row][col]=1;
        count++;
        dfs(row+1,col,parrow,parcol,visited,grid,count);
        dfs(row-1,col,parrow,parcol,visited,grid,count);
        dfs(row,col+1,parrow,parcol,visited,grid,count);
        dfs(row,col-1,parrow,parcol,visited,grid,count);
    }
    int largestIsland(vector<vector<int>>& grid) {
        int maxi = 0;
        map<pair<int,int>,int> dp;
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j] and !visited[i][j])
                {
                    int count=0;
                    dfs(i,j,i,j,visited,grid,count);
                    dp[{i,j}]=count;
                    maxi=max(maxi,count);
                }
            }
        }
        vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j] == 0)
                {
                     int ans = 0;
                     set<pair<int,int>> st;
                     for(int k=0;k<dir.size();k++)
                     {
                         int newx = i + dir[k][0];
                         int newy = j + dir[k][1];

                         if(mp.find({newx,newy})!=mp.end())
                         {
                            if(st.find(mp[{newx,newy}])!=st.end())continue;
                            ans+=dp[mp[{newx,newy}]];
                            st.insert(mp[{newx,newy}]);
                         }
                     }
                maxi=max(maxi,ans+1);
                }
            }
        }
        return maxi;

    }
};