class Solution {
public:
    vector<vector<int>> adj;
    vector<int> group;
    vector<long long> total;
    long long ans = 0;

    vector<long long> dfs(int u, int parent) {
        vector<long long> cnt(21, 0);
        cnt[group[u]] = 1;

        for (int v : adj[u]) {
            if (v == parent) continue;
            auto child = dfs(v, u);
            for (int i = 0; i < 21; i++) {
                cnt[i] += child[i];
            }
        }

        for (int i = 0; i < 21; i++) {
            ans += cnt[i] * (total[i] - cnt[i]);
        }

        return cnt;
    }

    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& groupInput) {
        group = groupInput;
        adj.assign(n, {});
        total.assign(21, 0);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        for (int g : group) total[g]++;

        dfs(0, -1);
        return ans;
    }
};
