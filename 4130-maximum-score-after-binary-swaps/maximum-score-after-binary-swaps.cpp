class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        priority_queue<long long> pq;
        long long sum = 0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == '1')
            {
                if(!pq.empty() and pq.top() >= nums[i])
                {
                    sum += pq.top();
                    pq.pop();
                    pq.push(nums[i]);
                }else{
                    sum += nums[i];
                }
            }else{
                pq.push(nums[i]);
            }
        }
        return sum;
    }
};