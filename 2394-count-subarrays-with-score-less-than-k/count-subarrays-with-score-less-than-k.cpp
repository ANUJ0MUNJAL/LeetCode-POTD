class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0;
        long long sum = 0;
        int slow = 0;
        for(int i=0;i<nums.size();i++){
             sum+=nums[i];
             while(slow <= i and sum*(i-slow+1) >= k){
                  ans += (nums.size()-i);
                  sum -= nums[slow];
                  slow++;
             }
        }
        long long res = nums.size()*(nums.size()+1)/2;
        return res - ans;
    }
};