class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
         priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>> pq;
         if(grid[0][0] != 0)return -1;
         if(grid.size() > 1 and grid[0].size() > 1 and grid[0][1] > 1 and grid[1][0] > 1)return -1;
         pq.push({0,0,0});
         vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
         vector<vector<int>> dir={{0,-1},{0,1},{1,0},{-1,0}};
         while(!pq.empty())
         {
            auto el = pq.top();
            pq.pop();
            if(el[1]==grid.size()-1 and el[2] == grid[0].size()-1)return el[0];
            for(int i=0;i<dir.size();i++)
            {
                int newx = el[1]+dir[i][0];
                int newy = el[2]+dir[i][1];

        if(newx >=0 and newy >=0 and newx < grid.size() and newy < grid[0].size() and !visited[newx][newy])
        {
            int val = el[0]+1;
            if(grid[newx][newy] <= val)
            {
                visited[newx][newy]=1;
                pq.push({val,newx,newy});
            }else{
                // if(el[1]==0 and el[2] == 0)continue;
                int diff = grid[newx][newy]-el[0];
                if(diff & 1)
                {
                    pq.push({grid[newx][newy],newx,newy});
                }else{
                    pq.push({grid[newx][newy]+1,newx,newy});
                }
                visited[newx][newy]=1;
            }
        }
            }

         }
         return -1;
    }
};