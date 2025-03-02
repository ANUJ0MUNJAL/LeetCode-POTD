class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int> mp;
        for(auto j: nums1)mp[j[0]]+=j[1];
         for(auto j: nums2)mp[j[0]]+=j[1];
         vector<vector<int>> ans;
         for(auto j: mp)
         {
            ans.push_back({j.first,j.second});
         }
         return ans;
    }
};