class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        map<int,int> mp;
        for(auto j: nums)mp[j]++;

        return mp[nums[nums.size()/2]]==1;
    }
};