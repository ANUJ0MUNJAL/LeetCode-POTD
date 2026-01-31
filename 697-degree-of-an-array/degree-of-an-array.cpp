class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> mp1;
        for(auto j: nums)mp1[j]++;
        int maxi = 0;
        for(auto j: mp1)maxi = max(maxi,j.second);
        
        map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]].push_back(i);
        }
        
        int ans = INT_MAX;
        for(auto j: mp)
        {
            if(j.second.size() == maxi)
            {
                 ans = min(ans,j.second.back() - j.second[0]+1);
            }
        }

        return ans;
       
    }
};