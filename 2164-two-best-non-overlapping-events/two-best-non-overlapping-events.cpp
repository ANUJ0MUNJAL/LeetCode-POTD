class Solution {
   
    
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        sort(events.begin(),events.end());
        int maxi = 0;
        int ans = 0;
        for(int i=0;i<events.size();i++)
        {
            while(!pq.empty() and pq.top().first < events[i][0])
            {
                 maxi=max(maxi,pq.top().second);
                 pq.pop();
            }
            ans=max(ans,maxi+events[i][2]);
            pq.push({events[i][1],events[i][2]});
        }
        return ans;
    }
};