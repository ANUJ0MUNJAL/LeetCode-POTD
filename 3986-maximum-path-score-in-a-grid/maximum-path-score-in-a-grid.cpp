class Solution {
public:
    vector<vector<vector<long long>>> dp;
    long long INF = 1e15;

    long long solve(vector<vector<int>>& grid, int i, int j, int k) {
        int n = grid.size(), m = grid[0].size();
        if (k < 0) return INF;
        if (i == n - 1 && j == m - 1) return 0;
        if (dp[i][j][k] != -1) return dp[i][j][k];

        long long best = -INF;
        if (i + 1 < n) {
            int val = (grid[i + 1][j] >= 1) ? 1 : 0;
            long long down = solve(grid, i + 1, j, k - val);
            if (down != INF) best = max(best, down + grid[i + 1][j]);
        }
        if (j + 1 < m) {
            int val = (grid[i][j + 1] >= 1) ? 1 : 0;
            long long right = solve(grid, i, j + 1, k - val);
            if (right != INF) best = max(best, right + grid[i][j + 1]);
        }

        return dp[i][j][k] = (best == -INF ? INF : best);
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        dp.assign(n, vector<vector<long long>>(m, vector<long long>(k + 1, -1)));
        long long value = solve(grid, 0, 0, k);
        return (value >= INF) ? -1 : (int)value;
    }
};
