class Solution {
public:
    long long dp[501][501][3];
    int solve(vector<vector<int>>&arr,int row,int col,int k)
    {
          if(row == arr.size()-1 and col == arr[0].size()-1)
          {
             if(k > 0 and arr[row][col] < 0)return 0;
             return arr[row][col];
          }
          if(row >= arr.size() or col >= arr[0].size())return -1e7;
          if(dp[row][col][k]!=-1)return dp[row][col][k];
          int include=-1e7;
          if(k > 0 and arr[row][col] < 0)
          {
              include=max(solve(arr,row+1,col,k-1),solve(arr,row,col+1,k-1));
          }
          int exclude=arr[row][col]+max(solve(arr,row+1,col,k),solve(arr,row,col+1,k));
          return dp[row][col][k]=max(include,exclude);


    }
    int maximumAmount(vector<vector<int>>& coins) {
        memset(dp,-1,sizeof(dp));
        return solve(coins,0,0,2);
    }
};