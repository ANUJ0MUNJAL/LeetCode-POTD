class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        if(nums.size() <=3)return 0;
        sort(nums.begin(),nums.end());
        
        return min({nums[nums.size()-1]-nums[2],nums[nums.size()-3]-nums[0],nums[nums.size()-2]-nums[1]});

    }
};