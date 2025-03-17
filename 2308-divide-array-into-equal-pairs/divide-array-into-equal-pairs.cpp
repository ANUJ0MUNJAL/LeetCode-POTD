class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int,int> mp;
        for(auto j: nums)
        {
            mp[j]++;
        }
        for(auto j: mp)
        {
            if(j.second & 1)return false;
        }
        return true;
    }
};