class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxsum = 0;
        int sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum < 0)
            {
               sum = 0;
            }
            maxsum = max(maxsum,sum);
        }
        sum = 0;
        int minsum = 0;

        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum > 0)
            {
               sum = 0;
            }
            minsum = min(minsum,sum);
        }

        return max(maxsum,abs(minsum));
    }
};