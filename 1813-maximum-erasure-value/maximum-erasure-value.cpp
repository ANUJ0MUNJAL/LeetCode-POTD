class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int start=0;
        int sum=0;
        map<int,int> mp;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            sum+=nums[i];
            while(start < i and mp[nums[i]] > 1)
            {
                  mp[nums[start]]--;
                  sum-=nums[start];
                  start++;
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};