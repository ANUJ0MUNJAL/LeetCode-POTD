class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int> dq;
        dq.push_back(0);
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];

        for(int i=1;i<nums.size();i++)
        {
            while(dq.size() > 0 and  i - dq.front() > k)dq.pop_front();

        
            dp[i] = dp[dq.front()] + nums[i];

            while(dq.size() > 0 and dp[dq.back()]  <= dp[i])dq.pop_back();

            dq.push_back(i);
        }
        return dp[nums.size()-1];
    }
};