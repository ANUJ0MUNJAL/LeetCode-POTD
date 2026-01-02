class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        map<int,int> mp;
        for(auto j: nums)mp[j]++;
        for(auto j: mp)if(j.second == nums.size()/2)return j.first;
        return -1;
    }
};