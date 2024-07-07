class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& nums) {
              int count=0;
        if(nums[nums.size()-1]!=nums[0] and nums[0]!=nums[1])count++;
        if(nums[nums.size()-2]!=nums[nums.size()-1] and nums[nums.size()-1]!=nums[0])count++;
        for(int i=1;i<nums.size()-1;i++){
             if(nums[i-1] != nums[i] and nums[i]!=nums[i+1])count++;
        }
        return count;
    }
};