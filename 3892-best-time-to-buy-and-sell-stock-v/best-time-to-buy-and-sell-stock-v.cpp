class Solution {
public:
    long long dp[1001][1001][4];
    long long solve(vector<int>&prices,int index,int buy,int k)
    {
        if(k == 0)
        {
            if(buy != -1)return -1e18;
            return 0;
        }
        if(index >= prices.size())
        {
             if(k < 0 or buy != -1)return -1e18;
             return 0;
        }
        if(k < 0)return -1e18;
        if(dp[index][k][buy+1] != -1)return dp[index][k][buy+1];

        long long res = 0;
        if(buy == -1)
        {
            return dp[index][k][buy+1]= max({1ll*-prices[index]+solve(prices,index+1,0,k),1ll*prices[index]+solve(prices,index+1,1,k),1ll*solve(prices,index+1,-1,k)});
        }else if(buy == 1)
        {
          return dp[index][k][buy+1]=   max(1ll*-prices[index]+solve(prices,index+1,-1,k-1),1ll*solve(prices,index+1,1,k));
        }else if(buy == 0)
        {
           return dp[index][k][buy+1]=  max(1ll*prices[index]+solve(prices,index+1,-1,k-1),1ll*solve(prices,index+1,0,k));
        }
        return res;


    }
    long long maximumProfit(vector<int>& prices, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(prices,0,-1,k);
    }
};