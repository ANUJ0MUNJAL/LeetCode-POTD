class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>> pq;
        if(grid[0][0] == 1)
        {
            pq.push({1,0,0});
        }else{
            pq.push({0,0,0});
        }
        vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        visited[0][0]=1;
        while(!pq.empty())
        {
             auto el = pq.top();
             pq.pop();
             if(el[1] == grid.size()-1 and el[2] == grid[0].size()-1)
             {
                return el[0];
             }
           
             for(int i=0;i<dir.size();i++)
             {
                  int newx = el[1]+dir[i][0];
                  int newy = el[2]+dir[i][1];
              
    if(newx >=0 and newy >=0 and newx < grid.size() and newy < grid[0].size() and !visited[newx][newy])
                  {
                      visited[newx][newy]=1;
                      if(grid[newx][newy] == 0)
                      {
                        pq.push({el[0],newx,newy});
                      }else{
                        pq.push({el[0]+1,newx,newy});
                      }
                  }
             }

        }
        return -1;
    }
};