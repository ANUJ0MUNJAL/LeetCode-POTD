class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        vector<int> prefix(nums.size(),0);
        prefix[0] = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            prefix[i] = max(prefix[i-1],nums[i]);
        }
        int ans = 0;
        for(int i=k;i<nums.size();i++)
        {
            ans = max(ans,nums[i] + prefix[i-k]);
        }
        return ans;

    }
};