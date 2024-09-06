class Solution {
public:
    long long dp[5001][2];
    int solve(vector<int>&prices,int index,bool flag)
    {
        if(index >= prices.size())return 0;
        if(dp[index][flag]!=-1)return dp[index][flag];
        int buy=0,sell=0;
        if(flag)
        {
             buy=max(-prices[index]+solve(prices,index+1,0),solve(prices,index+1,flag));
        }else
        {
             sell=max(prices[index]+solve(prices,index+2,1),solve(prices,index+1,flag));
        }
        return dp[index][flag]=max(buy,sell);
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(prices,0,1);

    }
};