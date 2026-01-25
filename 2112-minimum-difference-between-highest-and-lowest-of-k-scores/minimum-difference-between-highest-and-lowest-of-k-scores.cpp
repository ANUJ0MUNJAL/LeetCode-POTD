class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
       sort(nums.begin(),nums.end());
       int ans = nums[nums.size()-1]-nums[0];
       for(int i=0;i<nums.size();i++)
       {
           if(i + k -1 < nums.size())
           {
               ans = min(ans,nums[i+k-1] - nums[i]);
           }
       }
       return ans;
    }
};