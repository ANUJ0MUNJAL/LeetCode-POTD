class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        vector<int> dp(numWays.size()+1,0);
        dp[0]=1;
        for(int i=0;i<numWays.size();i++)dp[i+1]=numWays[i];
        vector<int> ans;
        for(int i=1;i<=numWays.size();i++)
        {
            if(dp[i] > 1)return {};
            if(dp[i] == 0)continue;
            ans.push_back(i);
            for(int j=numWays.size();j>=i;j--)
            {
                
                dp[j] -= dp[j-i];
                if(dp[j] < 0)return {};
            }
        }
        return ans;
    }
};