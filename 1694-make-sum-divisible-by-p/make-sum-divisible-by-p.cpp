class Solution {
public:
    int minSubarray(vector<int>& nums, int k) {
    //    (sum - (prefix[i] - prefix[j]) ) % k = 0;
    //     sum - prefix[i]%k + prefix[j]%k = 0;
    //     sum%k + prefix[j]%k = prefix[i]%k
        
    //     i - j minimize 

    //     j (max)
    //     i ()
       long long ans = INT_MAX;
        map<long long,int> mp;
        long long sum = accumulate(nums.begin(),nums.end(),0LL);
        if(sum % k == 0)return 0;
        vector<long long> prefix;
        for(int i=0;i<nums.size();i++)
        {
            if(i == 0)prefix.push_back(nums[i]);
            else prefix.push_back(prefix.back()+nums[i]);
        }
        mp[0]= -1;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find((prefix[i] % k- sum %k + k)%k) != mp.end())
            {
                ans = min(ans,1ll*(i - mp[(prefix[i]%k - sum%k + k)%k]));
            }
            mp[prefix[i] % k] = i;
        }
        return ans >= nums.size() ? -1 : ans;
    }
};