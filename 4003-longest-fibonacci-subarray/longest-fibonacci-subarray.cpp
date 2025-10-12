class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int prev = 0;
        int curr = 1;
        int maxi = 2;
        int ans = maxi;
        for(int i=2;i<nums.size();i++)
        {
            if(nums[prev] + nums[curr] == nums[i])
            {
                maxi++;
                ans = max(ans,maxi);
                prev = curr;
                curr = i;
            }else{
                prev = curr;
                curr = i;
                maxi = 2;
            }

        }
        return ans;
    }
};