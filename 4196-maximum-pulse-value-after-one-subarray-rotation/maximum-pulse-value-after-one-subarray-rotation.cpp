class Solution {
public:
     long long maxValue(vector<int>& A) {
        long long p = 0, dmin = 0;
        long long pmax[2] = {(long)-1e18, 0};
        for (int i = 0; i < A.size(); ++i) {
            p += (i & 1) ? -A[i] : A[i];
            dmin = min(dmin, p - pmax[i & 1]);
            pmax[i & 1] = max(pmax[i & 1], p);
        }
        return p - dmin - dmin;
    }
};