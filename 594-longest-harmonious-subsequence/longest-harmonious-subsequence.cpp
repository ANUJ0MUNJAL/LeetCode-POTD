class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> mp;
        for(auto j: nums)mp[j]++;
        int maxi = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(mp[nums[i] - 1] != 0)
            maxi = max(maxi,mp[nums[i]] + mp[nums[i] - 1]);
            if(mp[nums[i] + 1] != 0)
            maxi = max(maxi,mp[nums[i]] + mp[nums[i] + 1]);
        }
        return maxi;

    }
};