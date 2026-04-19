class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> left;
        for(int i=0;i<nums.size();i++)
        {
            if(i == 0)left.push_back(nums[i]);
            else
            {
                left.push_back(max(left.back(),nums[i]));
            }
        }
        vector<int> right;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(i == nums.size()-1)
            {
                right.push_back(nums[i]);
            }else{
                right.push_back(min(right.back(),nums[i]));
            }
        }
        reverse(right.begin(),right.end());

        for(int i=0;i<nums.size();i++)
        {
    
            if((left[i] - right[i]) <= k)return i;
        }
        return -1;
    }
};