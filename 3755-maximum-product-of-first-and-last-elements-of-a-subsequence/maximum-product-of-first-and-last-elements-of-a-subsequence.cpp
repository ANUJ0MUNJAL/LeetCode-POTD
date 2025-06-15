class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        vector<pair<int,int>> arr;
        long long maxi=LONG_LONG_MIN,mini=LONG_LONG_MAX;
        for(int i=0;i<nums.size();i++)
        {
             maxi = max(maxi,1ll*nums[i]);
             mini = min(mini,1ll*nums[i]);
             arr.push_back({maxi,mini});
        }
       
        long long ans = LONG_LONG_MIN;
        for(int i=0;i<nums.size();i++)
        {
            
            if(i - m + 1 >= 0)
            {
                ans = max(ans,1ll*nums[i]*arr[i-m+1].first);
                ans = max(ans,1ll*nums[i]*arr[i-m+1].second);
            }
          
        }
        return ans;
    }
};