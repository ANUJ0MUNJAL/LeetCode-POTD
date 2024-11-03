class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>> pq;
        pq.push({0,0,0});
        vector<vector<int>> dir={{1,0},{-1,0},{0,-1},{0,1}};
        vector<vector<int>> visited(moveTime.size(),vector<int>(moveTime[0].size(),false));
        visited[0][0]=false;
        while(!pq.empty())
        {
             auto el = pq.top();
             pq.pop();
           
             if(el[1] == moveTime.size()-1 and el[2] == moveTime[0].size()-1)
             {
                 return el[0];
             }
             for(int i=0;i<dir.size();i++)
             {
                 int newx = el[1]+dir[i][0];
                 int newy = el[2]+dir[i][1];
              
                 if(newx >=0 and newy >=0 and newx < moveTime.size() and newy < moveTime[0].size() and 
                 !visited[newx][newy])
                 {
                     pq.push({max(el[0]+1,moveTime[newx][newy]+1),newx,newy});
                     visited[newx][newy]=1;
                 }
             }

        }
        
        return -1;
        
    }
};