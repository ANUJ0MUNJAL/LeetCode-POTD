class Solution {
public:
    bool solve(vector<int>&a,int maxi)
    {
            long ex = 0;
        for (int i : a) {
            if (i > maxi) {
                long c = (i - maxi);
                if (c > ex) return false;
                ex -= c;
            } else {
                ex += (maxi- i);
            }
        }
        return true;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int start =0;
        int end = 1e9;
        int ans = 0;
        while(start <= end)
        {
            int mid = start+(end-start)/2;
            cout<<mid<<endl;
            if(solve(nums,mid))
            {
                ans = mid;
                end = mid-1;
            }else{
                start = mid + 1;
            }
        }
        return ans;

    }
};