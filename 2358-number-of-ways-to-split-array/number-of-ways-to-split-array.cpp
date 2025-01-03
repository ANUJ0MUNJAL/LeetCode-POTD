class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = accumulate(nums.begin(),nums.end(),0LL);
        
        long long count=0;
        int ans = 0;
        for(int i=0;i<nums.size()-1;i++)
        {
           count+=nums[i];
           sum-=nums[i];
           if(count >= sum)ans++;
        }
        return ans;
    }
};