class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        map<int,int> mp;
        vector<int> ans;
        for(auto j: nums)
        {
            mp[j]++;
            if(mp[j] <= k)ans.push_back(j);
        }
        return ans;
    }
};