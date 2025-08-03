class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fr, int sp, int k) {
        int n = 2e5 + 1;
        vector<int> v(n, 0);
        for(auto& x : fr) {
            v[x[0]] = x[1]; 
        }
        
        long long ans = 0;        
        vector<long long> left(n, 0), right(n, 0); 
        left[sp] = v[sp];
        right[sp] = v[sp];
        for(int i=sp-1; i>=0; i--) {
            left[i] = left[i+1] + v[i];
        }
        for(int i=sp+1; i<n; i++) {
            right[i] = right[i-1] + v[i];
        }
        
        for(int i=0; i<=min(k, sp); i++) { 
            int r = min(k-2*i, n-1-sp); 
            if(r>=0 && sp+r<n) {
                ans = max(ans, left[sp-i] + right[sp+r] - v[sp]);
            }
        }
        
        for(int i=0; i<=min(k, n-1-sp); i++) { 
            int l = min(k-2*i, sp); 
            if(l>=0 && sp-l>=0) {
                ans = max(ans, left[sp-l] + right[sp+i] - v[sp]);
            }
        }
        return (int)ans;
    }
};