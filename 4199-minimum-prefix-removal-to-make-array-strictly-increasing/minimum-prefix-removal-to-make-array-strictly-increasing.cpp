class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int j = nums.size()-2;
        while(j >= 0)
        {
            if(nums[j] >= nums[j+1])
            {
                return j+1;
            }
            j--;
        }
        return 0;

    }
};