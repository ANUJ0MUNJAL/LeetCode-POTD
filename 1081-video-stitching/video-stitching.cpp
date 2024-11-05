class Solution {
public:
    long long dp[101][101];
    int solve(vector<vector<int>>&arr,int index,int time,int end)
    {
          if(end >= time)return 0;
          if(index >= arr.size())return 1e9;
          if(dp[index][end+1]!=-1)return dp[index][end+1];
          int include=1e9;
          if((end == -1 and arr[index][0] == 0) or arr[index][0] <= end)
          {
               include=1+solve(arr,index+1,time,arr[index][1]);
          }
          int exclude = solve(arr,index+1,time,end);
          return dp[index][end+1]=min(include,exclude);
    }
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(),clips.end());
        memset(dp,-1,sizeof(dp));
        int ans =  solve(clips,0,time,-1);
        if(ans == 1e9)return -1;
        return ans;
    }
};