class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int a = accumulate(nums.begin(),nums.begin()+k,0);
        int b = 0;
        for(int i=nums.size()-1;k--;i--)
        {
            b += nums[i];
        }
        return abs(a-b);
    }
};