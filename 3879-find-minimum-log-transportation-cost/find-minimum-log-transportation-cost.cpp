class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        long long cost =0;
        if(n > k)
        {
            cost += 1ll*k * (n-k);
        }
        else if(m > k)
        {
             cost += 1ll*k*(m-k);
        }
        return cost;
    }
};