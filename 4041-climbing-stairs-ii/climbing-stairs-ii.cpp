class Solution {
public:
    long long dp[100001];
    int solve(vector<int>&costs,int index)
    {
        if(index == costs.size()-1)return 0;
        if(index >= costs.size())return 1e9;
        if(dp[index] != -1)return dp[index];
        int value = 1e9;
        if(index + 1 < costs.size())
        {
             value = min(value,costs[index+1] + 1 + solve(costs,index+1));
        }
        if(index + 2 < costs.size())
        {
            value = min(value,costs[index+2]+4+solve(costs,index+2));
        }
        if(index+3 < costs.size())
        {
            value = min(value,costs[index+3]+9+solve(costs,index+3));
        }
        return dp[index] = value;
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int> temp;
        temp.push_back(0);
        for(auto j: costs)temp.push_back(j);
        memset(dp,-1,sizeof(dp));
        return solve(temp,0);
    }
};