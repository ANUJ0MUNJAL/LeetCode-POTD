class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int ans = INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums.size();j++)
            {
                if(i == j)continue;
                for(int k= 0;k<nums.size();k++)
                {
                    if(k == i or k == j)continue;
                    ans = max(ans,nums[i]+nums[j]-nums[k]);
                }
            }
        }
        return ans;

    }
};