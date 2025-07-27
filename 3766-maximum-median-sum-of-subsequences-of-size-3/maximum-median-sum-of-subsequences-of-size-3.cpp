class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long ans = 0;
        int count = 0;
        for(int i=nums.size()-2;i>count;i-=2)
        {
              ans += nums[i];
              count++;
        }
        return ans;
    }
};