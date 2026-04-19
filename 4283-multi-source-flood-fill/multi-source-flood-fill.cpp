class Solution {
public:
    bool safe(vector<vector<int>> &grid,int x, int y)
    {
        if(x >=0 and y >= 0 and x < grid.size() and y < grid[0].size() and grid[x][y] == 0)return true;
        return false;
    }
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> grid(n,vector<int>(m,0));
        priority_queue<array<int,3>> q;
        for(auto j: sources)
        {
            grid[j[0]][j[1]]=j[2];
            q.push({j[2],j[0],j[1]});
        }
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty())
        {
            priority_queue<array<int,3>> temp;
            int size= q.size();
            while(size--)
            {
                auto el = q.top();
                q.pop();
                for(int i=0;i<dir.size();i++)
                {
                    int x = el[1] + dir[i][0];
                    int y = el[2] + dir[i][1];
                
                    if(safe(grid,x,y))
                    {
                        grid[x][y] = el[0];
                        temp.push({el[0],x,y});
                    }
                }

                
            }
            q = temp;
        }
        return grid;
    }
};