class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(),nums.end());
        vector<int> dp(1e5+1,0);
        for(int i=0;i<nums.size();i++)
        {
             dp[nums[i]]=1;
        }
   
        for(int i=0;i<dp.size();i++)
        {
             int val = i;
             int temp = sqrt(i);
             if(dp[i]!=0 and temp != i and temp * temp == val)
             {
                dp[i]+=dp[temp];
             }
        }
       
        return *max_element(dp.begin(),dp.end()) <= 1 ? -1 : *max_element(dp.begin(),dp.end());
    }
};