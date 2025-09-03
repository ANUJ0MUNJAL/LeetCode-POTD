class Solution {
public:
   
        int numberOfPairs(vector<vector<int>>& A) {
        int res = 0, n = A.size();
        sort(begin(A), end(A), [](const auto &p, const auto &q){
            return p[0] == q[0] ? p[1] > q[1] : p[0] < q[0];
        });
        for (int i = 0; i < n; ++i) {
            int y = -2e9;
            for (int j = i + 1; j < n; ++j)
                if (A[i][1] >= A[j][1] && A[j][1] > y)
                    res++, y = A[j][1];
        }
        return res;
    }
};