class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
        pq.push({0, 0, 0});
        
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        
        while (!pq.empty()) {
            auto el = pq.top();
            pq.pop();
            
            int cost = el[0];
            int x = el[1];
            int y = el[2];
           
            if (visited[x][y]) continue;
            visited[x][y] = 1;
            
            if (x == rows - 1 && y == cols - 1) {
                return cost;
            }
           
            for (int dir = 1; dir <= 4; ++dir) {
                int newx = x + dx[dir - 1];
                int newy = y + dy[dir - 1];
              
                if (newx >= 0 && newx < rows && newy >= 0 && newy < cols && !visited[newx][newy]) {
                  
                    if (dir == grid[x][y]) {
                        pq.push({cost, newx, newy}); 
                    } else {
                        pq.push({cost + 1, newx, newy}); 
                    }
                }
            }
        }
        
        return -1; 
    }
};
