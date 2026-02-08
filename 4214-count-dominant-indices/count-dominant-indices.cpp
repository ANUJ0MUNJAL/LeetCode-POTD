class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        vector<int> prefix;
        int total = accumulate(nums.begin(),nums.end(),0);
        for(int i=0;i<nums.size();i++)
        {
            if(i == 0)prefix.push_back(nums[i]);
            else prefix.push_back(prefix.back()+nums[i]);
        }
        int n = nums.size();
        int count = 0;
        for(int i=0;i<nums.size();i++)
        {
            int value = total - prefix[i];

            double avg = (value*1.0)/(n-i-1);

            if(1.0*nums[i] > avg)
            {
                count++;
            }

        }
        return count;
    }
};