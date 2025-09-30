class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int> arr;
        while(nums.size()!=1)
        {
               for(int i=0;i<nums.size()-1;i++)
               {
                   arr.push_back((nums[i]+nums[i+1])%10);
               }
               nums=arr;
               arr.clear();
        }
        return nums[0];
    }
};