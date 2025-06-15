class Solution {
public:
    int mod =1e9+7;
    int specialTriplets(vector<int>& nums) {
        map<int,vector<int>> mp;

        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]].push_back(i);
        }
        long long ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            int val = 2*nums[i];
            
            auto itr =  lower_bound(mp[val].begin(),mp[val].end(),i)-mp[val].begin();
            long long left = itr;
            long long right = mp[val].size()-left;
            if(val == nums[i])
            {
                right--;
            }
            
            ans=(ans%mod + (left*right)%mod)%mod;


        }
        return ans;

    }
};