class Solution {
public:
    int dp[51][51][51];
    int solve(vector<int>&stones,int start,int end,int count,int k,vector<int>&prefix)
    {
        if(start == end and count==1)return 0;
        if(start == end)return 1e9;
        if(dp[start][end][count] != -1)return dp[start][end][count];


       if(count == 1)
       {
        return dp[start][end][count] = solve(stones,start,end,k,k,prefix) + (start == 0 ? prefix[end] : prefix[end]-prefix[start-1]);
       }else{
        int ans = 1e9;
        for(int i=start;i<end;i++)
        {
            ans = min(ans,solve(stones,start,i,1,k,prefix)+solve(stones,i+1,end,count-1,k,prefix));
        }
       return dp[start][end][count] = ans;
       }
       return -1;

    }
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
            if((n-1)%(k-1)!=0)
            return -1;
        vector<int> prefix(stones.size(),0);
        for(int i=0;i<stones.size();i++)
        {
            if(i == 0)
            {
                prefix[i] = stones[i];
            }else{
                prefix[i] = prefix[i-1]+stones[i];
            }
        }
        memset(dp,-1,sizeof(dp));
        return solve(stones,0,stones.size()-1,1,k,prefix);
    }
};