class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans=nums.size()*(nums.size()-1)/2;
        long long val=0;
        map<long long,long long> mp;
        for(int i=0;i<nums.size();i++){
            val+=mp[nums[i]-i];
            mp[nums[i]-i]++;
        }
        return ans-val;
    }
};