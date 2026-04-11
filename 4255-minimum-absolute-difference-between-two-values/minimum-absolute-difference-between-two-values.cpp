class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        map<int,int> mp;
        int ans = INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                if(mp.count(2))
                ans = min(ans,abs(mp[2]-i));
                mp[1]=i;

            }else if(nums[i]==2)
            {
                if(mp.count(1))
                 ans = min(ans,abs(i-mp[1]));
                 mp[2]=i;
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};