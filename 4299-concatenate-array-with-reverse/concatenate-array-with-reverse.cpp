class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int> temp = nums;
        for(int i=nums.size()-1;i>=0;i--)temp.push_back(nums[i]);
        return temp;
    }
};