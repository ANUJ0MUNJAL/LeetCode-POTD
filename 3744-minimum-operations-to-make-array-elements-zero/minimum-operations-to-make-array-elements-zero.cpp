class Solution {
public:
    long long solve(int l,int r)
    {
        long long S = 1;
        long long steps = 0;
        long long L = 1;
        while(L <= r)
        {
            long long R = 4*L-1;
            long long start = max(L,1ll*l); 
            long long end = min(R,1ll*r);

            if(start <= end)
            {
                steps+=(end-start+1)*S;
            }
            S++;
            L=R+1;
        }
        return steps;
    }
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for(auto j: queries)
        {
            int u = j[0];
            int v = j[1];
            long long steps = solve(u,v);
            ans+=(steps+1)/2;
        }
        return ans;
    }
};