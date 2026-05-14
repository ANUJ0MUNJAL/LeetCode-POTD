class Solution {
public:
    bool isGood(vector<int>& nums) {
        map<int,int> mp;
        for(auto j: nums)mp[j]++;
        int count = 0;
        for(auto j: mp)
        {
            if(j.first >= nums.size())return false;
            if(j.second == 2 and j.first == nums.size()-1)count++;
            else if(j.second >= 2)return false;

        }
        return count == 1;
        
        
    }
};