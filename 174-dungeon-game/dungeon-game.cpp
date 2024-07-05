class Solution {
public:
    long long dp[201][201];
    int solve(int row,int col,vector<vector<int>>&arr){
        if(row == arr.size()-1 and col==arr[0].size()-1){
              if(arr[row][col] <= 0){
                    return 1+abs(arr[row][col]);
              }else{
                return 1;
              }
        }
        if(row >= arr.size() or col >= arr[0].size()){
            return 1e9;
        }
         if(dp[row][col]!=-1)return dp[row][col];
        int front=-arr[row][col]+solve(row,col+1,arr);
        int down=-arr[row][col]+solve(row+1,col,arr);

        int val=min(front,down);
        if(val <= 0){
              return dp[row][col]=1;
        }else{
            return dp[row][col]=val;
        }

    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,dungeon);
    }
};