class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        vector<long long> left(nums.size(),0);
        vector<long long> right(nums.size(),0);
        for(int i=0;i<nums.size();i++)
        {
            if(i == 0)left[i] = nums[i];
            else left[i]+=(left[i-1] + nums[i]);
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(i == nums.size()-1)right[i] = nums[i];
            else{
                right[i] = min(right[i+1],1ll*nums[i]);
            }
        }
         long long ans = -1e18;
        for(int i=0;i<=nums.size()-2;i++)
        {
            ans = max(ans,left[i]-right[i+1]);
        }
        return ans;
    }
};