class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for(auto j: gifts)pq.push(j);
        while(k--)
        {
            auto el = pq.top();
            pq.pop();
            pq.push(sqrt(el));
        }
        long long sum=0;
        while(!pq.empty())
        {
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};