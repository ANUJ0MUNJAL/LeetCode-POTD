class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<pair<int,int>> cells(n*n+1);
        int index=1;
        vector<int>columns(n);
        for(int i=0;i<n;i++){
            columns[i]=i;
        }
        for(int i=n-1;i>=0;i--){
            for(auto j: columns){
                cells[index++]={i,j};
            }
            reverse(columns.begin(),columns.end());
        }
        vector<int> distance(n*n+1,-1);
        queue<int> q;
        q.push(1);
        distance[1]=0;
        while(!q.empty()){
            auto element=q.front();
            q.pop();
        for(int i=element+1;i<=min(element+6,n*n);i++){
        auto one=cells[i];
        int destination=(board[one.first][one.second]==-1)?i:board[one.first][one.second];
        if(distance[destination]==-1){
            distance[destination]=distance[element]+1;
            q.push(destination);
        }
            }
        }
        return distance[n*n];
    }
};