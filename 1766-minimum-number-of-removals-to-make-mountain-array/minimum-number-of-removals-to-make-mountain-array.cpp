class Solution {
public:
  
    int minimumMountainRemovals(vector<int>& nums) {
       vector<int> arr;
       vector<int> dp(nums.size());
       for(int i=0;i<nums.size();i++)
       {
           auto itr=lower_bound(arr.begin(),arr.end(),nums[i]);
           if(itr == arr.end())
           {
              arr.push_back(nums[i]);
           }else{
               *itr=nums[i];
           }
           dp[i]=arr.size();
       }
       arr.clear();
       vector<int> dp1(nums.size());
       for(int i=nums.size()-1;i>=0;i--)
       {
           auto itr = lower_bound(arr.begin(),arr.end(),nums[i]);
           if(itr == arr.end())
           {
             arr.push_back(nums[i]);
           }else{
            *itr=nums[i];
           }
           dp1[i]=arr.size();
       }
       int ans=0;
       for(int i=0;i<nums.size();i++)
       {
         if(dp[i]!=1 and dp1[i]!=1)
            ans=max(ans,dp[i]+dp1[i]-1);
       }
       return nums.size()-ans;
    }
};