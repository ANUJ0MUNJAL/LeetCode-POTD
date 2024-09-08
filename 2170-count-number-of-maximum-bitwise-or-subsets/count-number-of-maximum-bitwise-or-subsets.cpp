class Solution {
public:
    // long long dp[16][10000];
    int solve(vector<int>&nums,int index,int ans,int val)
    {
          if(index >= nums.size())
          {
              if(ans == val)return 1;
              return 0;
          }
        //   if(dp[index][val]!=-1)return dp[index][val];
          int include=solve(nums,index+1,ans,val|nums[index]);
          int exclude=solve(nums,index+1,ans,val);
          return include+exclude;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        // memset(dp,-1,sizeof(dp));
        int ans=0;
        for(auto j: nums)ans|=j;
        cout<<ans<<"\n";
        return solve(nums,0,ans,0);
    }
};