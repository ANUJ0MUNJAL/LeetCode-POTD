class Solution {
public:
    
    long long solve(vector<int>&robot,vector<int>&arr,int i,int j,vector<vector<long long>>&dp)
    {
        if(i >= robot.size())return 0;
        if(j >= arr.size())return 1e17;
        if(dp[i][j]!=-1)return dp[i][j];
        long long include=abs(robot[i]-arr[j])+solve(robot,arr,i+1,j+1,dp);
        long long exclude=solve(robot,arr,i,j+1,dp);
        return dp[i][j]=min(include,exclude);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        vector<int> arr;
        for(auto j: factory)
        {
              for(int i=0;i<j[1];i++)
              {
                arr.push_back(j[0]);
              }
        }
        vector<vector<long long>> dp(robot.size(),vector<long long>(arr.size(),-1));
        return solve(robot,arr,0,0,dp);
    }
};