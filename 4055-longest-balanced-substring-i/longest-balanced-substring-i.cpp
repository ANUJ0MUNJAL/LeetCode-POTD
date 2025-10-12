class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            vector<int> cnt(26, 0);
            for (int j = i; j < n; ++j) {
                cnt[s[j] - 'a']++;
                int freq = -1;
                bool balanced = true;
                for (int k = 0; k < 26; ++k) {
                    if (cnt[k] == 0) continue;
                    if (freq == -1) freq = cnt[k];
                    else if (cnt[k] != freq) { balanced = false; break; }
                }
                if (balanced) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};