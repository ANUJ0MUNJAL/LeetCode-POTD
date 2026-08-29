class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i;j<nums.size();j++)
            {
                long long val = pow(__gcd(nums[i],nums[j]),2);
                ans = max(ans,(1ll*nums[i] * nums[j])/val);
            }
        }
        return ans;
    }
};