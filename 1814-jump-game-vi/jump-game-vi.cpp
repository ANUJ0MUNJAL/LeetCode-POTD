class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        
        priority_queue<pair<int,int>> pq;

        pq.push({nums[0],0});

        int maxi = nums[0];

        for(int i=1;i<nums.size();i++)
        {
            while(!pq.empty() and i - pq.top().second > k)pq.pop();

            auto el = pq.top();

            int value = nums[i] + pq.top().first;

            maxi = value;

            pq.push({value,i});
        }
        return maxi;

    }
};