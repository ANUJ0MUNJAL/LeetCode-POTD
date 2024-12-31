class Solution {
public:
    int dp[366];
    int solve(vector<int>&days,vector<int>costs,int index)
    {
        if(index >= days.size())return 0;
        if(dp[index]!=-1)return dp[index];
        int a=1e7,b=1e7,c=1e7;

        a = costs[0]+solve(days,costs,index+1);

        auto idx = lower_bound(days.begin(),days.end(),days[index]+7)-days.begin();

        b= costs[1]+solve(days,costs,idx);

        idx = lower_bound(days.begin(),days.end(),days[index]+30)-days.begin();

        c = costs[2]+solve(days,costs,idx);

        return dp[index]=min({a,b,c});

    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        sort(days.begin(),days.end());
        memset(dp,-1,sizeof(dp));
         return solve(days,costs,0);
    }
};