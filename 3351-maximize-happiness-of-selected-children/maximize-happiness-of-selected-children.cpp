class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int> pq;
        for(auto j: happiness){
            pq.push(j);
        }
        int count=0;
        long long ans=0;
        while(k--){
            ans+=pq.top()-count;
            pq.pop();
            
            count++;
            if(pq.top()-count<=0){
                return ans;
            }
        }
        return ans;
    }
};