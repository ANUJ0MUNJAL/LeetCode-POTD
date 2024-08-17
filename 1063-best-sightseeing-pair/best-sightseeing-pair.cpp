class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        vector<int> dp(values.size(),0);
        dp[0]=0;
        int maxi=INT_MIN;
        for(int i=1;i<values.size();i++)
        {
            dp[i]=max(values[i-1]-1,dp[i-1]-1);
            maxi=max(maxi,dp[i]+values[i]);
        }
        return maxi;
       
    }
};