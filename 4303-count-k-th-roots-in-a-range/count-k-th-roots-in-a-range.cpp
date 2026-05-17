class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        if(k == 1)return r-l+1;
        int i = 0;
        int count = 0;
        while(true)
        {
            long long val = pow(i,k);
            if(val >= l and val <= r)count++;
            if(val > r)
            {
                break;
            }
            i++;

        }
        return count;
    }
};