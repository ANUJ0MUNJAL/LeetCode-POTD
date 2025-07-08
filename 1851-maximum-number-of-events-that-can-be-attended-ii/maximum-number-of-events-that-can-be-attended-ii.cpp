class Solution {
public:
    int solve(vector<vector<int>>&events,int index,int k,vector<vector<int>>&dp){
        if(index>=events.size() || k==0)
           return 0;
        if(dp[index][k]!=-1)
          return dp[index][k];
        int i;
       for(i=index+1;i<events.size();i++){
           if(events[i][0]>events[index][1])
             break;
       }
        return dp[index][k]=max(solve(events,index+1,k,dp),events[index][2]+solve(events,i,k-1,dp));
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        vector<vector<int>> dp(events.size(),vector<int>(k+1,-1));
        return solve(events,0,k,dp);
        
    }
};