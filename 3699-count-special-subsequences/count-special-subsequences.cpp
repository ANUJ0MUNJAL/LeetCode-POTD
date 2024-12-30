class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        // p / q = s / r
        map<double,int> mp;
        long long ans = 0;
        for(int r = 4 ; r < nums.size();r++)
        {
            int q = r - 2;

            for(int p = 0; p < q - 1 ; p++)
            {
                mp[1.00*nums[p]/nums[q]]++;
            }

            for(int s = r + 2;s < nums.size(); s++)
            {
                 ans += mp[1.00*nums[s]/nums[r]];
            }
        }
        return ans;
    }
};