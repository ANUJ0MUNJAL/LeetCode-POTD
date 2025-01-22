class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<vector<int>> arr(isWater.size(),vector<int>(isWater[0].size(),0));
        queue<pair<int,int>> q;
        vector<vector<int>> visited = arr;
        for(int i=0;i<isWater.size();i++)
        {
            for(int j=0;j<isWater[0].size();j++)
            {
                if(isWater[i][j]){
                    q.push({i,j});
                    visited[i][j]=1;
                }
            }
        }
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        int val = 1;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                for(int i=0;i<dir.size();i++)
                {
                    int newx = x + dir[i][0];
                    int newy = y + dir[i][1];

                    if(newx >= 0 and newy >= 0 and newx < arr.size() and newy < arr[0].size() and !visited[newx][newy])
                    {
                        visited[newx][newy]=1;
                        q.push({newx,newy});
                        arr[newx][newy]=val;
                    }
                }
            }
            val++;
        }
        return arr;
        
    }
};