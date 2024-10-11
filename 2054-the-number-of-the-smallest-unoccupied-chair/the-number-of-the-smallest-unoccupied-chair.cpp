class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<array<int,3>> arr;
        for(int i=0;i<times.size();i++)
        {
            arr.push_back({times[i][0],times[i][1],i});
        }
        sort(arr.begin(),arr.end());
        set<int> st;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int chair=0;
        for(int i=0;i<arr.size();i++)
        {
            while(!pq.empty() and pq.top().first <= arr[i][0])
            {
                st.insert(pq.top().second);
                pq.pop();
            }
            int val;
            if(!st.empty())
            {
                 val = *st.begin();
                st.erase(st.begin());
            }else{
                val = chair++;
            }
            if(arr[i][2] == targetFriend)return val;
            pq.push({arr[i][1],val});
        }
    
    return -1;
    }
};