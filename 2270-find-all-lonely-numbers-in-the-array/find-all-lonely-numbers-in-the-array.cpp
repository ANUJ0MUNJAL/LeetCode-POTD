class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        map<int,int> mp;
        for(auto j: nums)
        {
            mp[j]++;
        }
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
             
             if((mp[nums[i]] == 1) and (mp.count(nums[i]-1) == 0) and (mp.count(nums[i]+1) == 0))ans.push_back(nums[i]);
        }
        return ans;
    }
};