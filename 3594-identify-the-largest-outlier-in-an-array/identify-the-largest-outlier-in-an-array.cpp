class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        multiset<int> st(nums.begin(),nums.end());
        sort(nums.begin(),nums.end(),greater<int>());
        int sum = accumulate(nums.begin(),nums.end(),0);
        map<int,int> mp;
        for(auto j: nums)mp[j]++;
        for(int i=0;i<nums.size();i++)
        {
             int val = sum - nums[i];
        
             if(val % 2 == 0 and st.find(val/2) != st.end())
             {
                if(val / 2 == nums[i] and mp[nums[i]] > 1)return nums[i];
                else if(val / 2 != nums[i])
                return nums[i];
                else continue;
             }
        }
        return -1;
    }
};