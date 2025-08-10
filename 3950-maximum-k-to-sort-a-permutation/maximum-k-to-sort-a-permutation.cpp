class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(),temp.end());
        int val = INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(temp[i] != nums[i])
            {
                val &= nums[i];
                
            }
        }
        
        return val == INT_MAX ? 0 : val;
    }
};