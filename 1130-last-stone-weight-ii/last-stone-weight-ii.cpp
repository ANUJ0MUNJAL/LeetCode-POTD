class Solution {
public:
    long long dp[31][6001];
    int solve(vector<int>&arr,int index,int sum)
    {
        if(index >= arr.size())
        {
            return sum < 0 ? 1e6 : sum;
        }
        if(dp[index][sum+3000]!=-1)return dp[index][sum+3000];
         int include=1e6,exclude=1e6;
         include=solve(arr,index+1,sum+arr[index]);
         exclude=solve(arr,index+1,sum-arr[index]);
         return dp[index][sum+3000]=min(include,exclude);
        
    }
    int lastStoneWeightII(vector<int>& stones) {
        memset(dp,-1,sizeof(dp));
        return solve(stones,0,0);
    }
};