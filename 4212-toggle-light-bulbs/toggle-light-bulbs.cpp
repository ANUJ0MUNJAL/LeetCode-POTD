class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        map<int,int> mp;
        vector<int> ans;
        for(auto j: bulbs)mp[j]++;
        for(auto j: mp)
        {
            if(j.second & 1)ans.push_back(j.first);
        }
        return ans;
    }
};