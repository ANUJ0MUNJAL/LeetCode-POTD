class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        if(nums.size() < 3)return 0;
        if(nums[1] - nums[0] == nums[2] - nums[1])dp[2]=1;
        int sum=dp[2];
        for(int i=3;i<nums.size();i++)
        {
             if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) dp[i]+=1+dp[i-1];
             sum+=dp[i];
        }
        return sum;
    }
};