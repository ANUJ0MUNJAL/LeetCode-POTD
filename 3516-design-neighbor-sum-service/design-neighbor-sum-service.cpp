class neighborSum {
public:
    map<int,int> mp,dp;
    
    vector<vector<int>> temp;
    neighborSum(vector<vector<int>>& grid) {
        temp=grid;
        for(int i=0;i<temp.size();i++){
             for(int j=0;j<temp[0].size();j++){
                 if(i-1>=0)
                   mp[temp[i][j]]+=grid[i-1][j];
                 if(i+1 < temp.size())
                   mp[temp[i][j]]+=temp[i+1][j];
                 if(j-1>=0)
                   mp[temp[i][j]]+=grid[i][j-1];
                 if(j+1 < temp[0].size())
                   mp[temp[i][j]]+=grid[i][j+1];
                 if(i-1 >=0 and j-1 >=0){
                     dp[temp[i][j]]+=grid[i-1][j-1];
                 }
                 if(i-1 >=0 and j+1 < temp[0].size()){
                     dp[temp[i][j]]+=grid[i-1][j+1];
                 }
                 if(i+1 < temp.size() and j-1 >=0){
                     dp[temp[i][j]]+=grid[i+1][j-1];
                 }
                 if(i+1<temp.size() and j+1 < temp[0].size()){
                     dp[temp[i][j]]+=grid[i+1][j+1];
                 }
             }
        }
    }
    
    int adjacentSum(int value) {
        return mp[value];
    }
    
    int diagonalSum(int value) {
        return dp[value];
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */