class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0, high = n - 1, mod = 1e9+7;
        vector<int> pow(n, 1);
        for(int i = 1; i < n; ++i){
            pow[i] = (pow[i - 1] * 2) % mod;
        }
        int res = 0;
        while(low <= high){
            if(nums[low] + nums[high] > target) high--;
            else{
                res = (res + pow[high - low]) % mod;
                low++;
            }
        }
        return res;
    }
};