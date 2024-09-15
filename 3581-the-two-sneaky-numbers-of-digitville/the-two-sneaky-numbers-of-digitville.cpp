class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        map<int,int> mp;
        for(auto j: nums)mp[j]++;
        vector<int> ans;
        for(auto j: mp)
        {
            if(j.second == 2)ans.push_back(j.first);
        }
        return ans;
    }
};