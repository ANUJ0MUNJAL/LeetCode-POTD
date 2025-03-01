class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i] == nums[i+1])
            {
                nums[i]=2*nums[i];
                nums[i+1]=0;
            }
        }
        vector<int> arr(nums.size(),0);
        int i=0;
        for(auto j: nums)
        {
             if(j != 0)
             {
                arr[i]=j;
                i++;
             }
        }
        return arr;
    }
};