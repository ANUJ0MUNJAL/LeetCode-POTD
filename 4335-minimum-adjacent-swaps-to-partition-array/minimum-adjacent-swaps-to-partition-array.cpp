class Solution {
public:
    int mod = 1e9+7;
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        long long ans = 0;

        long long m = 0;
        long long r = 0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] < a)
            {
                ans = (ans%mod + (m%mod + r%mod)%mod)%mod;
            }else if(nums[i] >= a and nums[i] <= b)
            {
                ans = (ans%mod + r%mod)%mod;
                m ++;
            }else{
                r++;
            }
            
        }
        return ans;
    }
};