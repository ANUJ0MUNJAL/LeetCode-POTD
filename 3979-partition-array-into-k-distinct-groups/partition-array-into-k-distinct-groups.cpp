class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        if(nums.size()==1)return true;
        map<int,int> mp;
        for(auto j: nums)mp[j]++;
        int total = nums.size();
        int maxi = 0;
        for(auto j: mp)maxi=max(maxi,j.second);
        if(nums.size() % k != 0 or maxi >= (nums.size()/k)+1)return false;
        return true;
    
    }
};