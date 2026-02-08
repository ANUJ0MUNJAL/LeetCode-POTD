class Solution {
public:
    long long VAL = -4e18;
    long long dp[101][101][101];
    long long solve(vector<int>&nums1,vector<int>&nums2,int i,int j,int k)
    {
        if(k == 0)
        {
            return 0;
        }

        if(i >= nums1.size() || j >= nums2.size())
        {
            if(k == 0)return 0;
            return VAL;
        }
        if(nums1.size() - i < k or nums2.size() - j < k)return VAL;
      
        if(dp[i][j][k] != VAL)return dp[i][j][k];

        long long include = VAL;
        include = 1ll*nums1[i]*nums2[j];
        long long value = solve(nums1,nums2,i+1,j+1,k-1);
        if(value == VAL)
        {
            include = VAL;
        }else{
            include += value;
        }

        long long b = solve(nums1,nums2,i+1,j,k);
        long long c = solve(nums1,nums2,i,j+1,k);
        return dp[i][j][k] = max({include,b,c});
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        for(int i=0;i<101;i++)
        {
            for(int j=0;j<101;j++)
            {
                for(int k=0;k<101;k++)
                {
                    dp[i][j][k] = VAL;
                }
            }
        }
        return solve(nums1,nums2,0,0,k);

    }
};