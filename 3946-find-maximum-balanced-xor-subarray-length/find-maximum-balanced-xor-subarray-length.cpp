class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        map<pair<int,int>,int> mp;
        int odd = 0,even = 0;
        int x = 0;
        int ans = 0;
        mp[{0,0}] = -1;
        for(int i=0;i<nums.size();i++)
        {
            x ^= nums[i];
            if(nums[i] & 1)odd++;
            else even++;

            int val = odd - even;
            if(mp.find({val,x}) != mp.end())
            {
                ans = max(ans,i - mp[{val,x}]);
            }else{
                mp[{val,x}] = i;
            }
        }
        return ans;
    }
};