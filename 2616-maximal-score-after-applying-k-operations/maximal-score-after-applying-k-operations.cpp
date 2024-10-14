class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long> pq;
        for(auto j: nums)pq.push(j);
        long long ans=0;
        while(k--)
        {
            auto el = pq.top();
            pq.pop();
            ans+=el;
            pq.push((el+2)/3);
        }
        return ans;
    }
};