class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        const long long MOD = 1000000007LL;

        long long sum = 0;
        for (int x : nums) sum += x;

        if (sum <= k) return 0;

        long long n = (sum - 1) / k;

        return (int)(((__int128)n * (n + 1) / 2) % MOD);
    }
};