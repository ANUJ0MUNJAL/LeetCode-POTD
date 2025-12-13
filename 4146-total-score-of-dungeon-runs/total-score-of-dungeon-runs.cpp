class Solution {
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
      
        int n = damage.size();
        vector<long long> ps(n + 1);
        for (int i = 1; i <= n; i++) ps[i] = ps[i - 1] + damage[i - 1];

        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            int c = requirement[i - 1] - hp + ps[i];
            int idx = lower_bound(ps.begin(), ps.begin() + i + 1, c) - ps.begin();
            idx = min(idx, i);
            ans += (i - idx);
        }

        return ans;
    }
};