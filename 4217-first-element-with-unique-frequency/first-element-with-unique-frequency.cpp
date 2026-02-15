class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        map<int,int> mp;
        map<int,int> freq;
        for(auto j: nums)
        {
            freq[j]++;
        }
        for(auto j: freq)
        {
            mp[j.second]++;
        }

        for(int i=0;i<nums.size();i++)
        {
            int value = freq[nums[i]];
            if(mp[value] == 1)return nums[i];
        }
        return -1;
    }
};