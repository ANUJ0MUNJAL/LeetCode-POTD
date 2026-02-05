class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int n = nums.size();
         for(int i=0;i<nums.size();i++)
         {
            if(nums[i] == 0)
            {
                ans[i] = nums[i];
            }else if(nums[i] > 0)
            {
                ans[i] = nums[(i + nums[i])%nums.size()];
            }else{
                ans[i] = nums[((i+nums[i])%n + n)%n];
            }


         }
         return ans;
    }
};