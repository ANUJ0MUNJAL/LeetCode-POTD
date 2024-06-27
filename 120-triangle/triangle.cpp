class Solution {
public:
    long long dp[201][201];
    int solve(vector<vector<int>>&arr,int index,int level){
          if(index >= arr.size()) return 0;
          if(dp[index][level] != -1)return dp[index][level];
          int include=INT_MAX;
          int exclude=INT_MAX;
          
           
         include= arr[index][level]+solve(arr,index+1,level);     
         if(level < arr[index].size())
         exclude=arr[index][level]+solve(arr,index+1,level+1);
         return dp[index][level]=min(include,exclude);

    }
    int minimumTotal(vector<vector<int>>& arr) {
        memset(dp,-1,sizeof(dp));
        return solve(arr,0,0);
    }
};