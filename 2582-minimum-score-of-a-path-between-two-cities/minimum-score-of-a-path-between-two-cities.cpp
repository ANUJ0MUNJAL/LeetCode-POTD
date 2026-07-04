class Solution {
public:
    int ans = INT_MAX;
    vector<int> vis;

    void dfs(int source, map<int, vector<pair<int,int>>>& mp) {
        vis[source] = 1;

        for (auto neigh : mp[source]) {
            ans = min(ans, neigh.second);

            if (!vis[neigh.first]) {
                dfs(neigh.first, mp);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        map<int, vector<pair<int,int>>> mp;

        for (auto &j : roads) {
            mp[j[0]].push_back({j[1], j[2]});
            mp[j[1]].push_back({j[0], j[2]});
        }

        vis.assign(n + 1, 0);

        dfs(1, mp);

        return ans;
    }
};