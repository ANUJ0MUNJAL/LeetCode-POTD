class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<int> roomused(n,0);
        priority_queue<pair<long long int,long long int>,vector<pair<long long int,long long int>>,greater<pair<long long int,long long int>>> used;
        priority_queue<int,vector<int>,greater<int>> available;

        for(int i=0;i<n;i++){
            available.push(i);
        }

        for(int i=0;i<meetings.size();i++){
          
          long long int start=meetings[i][0];
          long long int end=meetings[i][1];
          long long int time=end-start;

          while(!used.empty() and used.top().first <= start){
              long long int room=used.top().second;
              used.pop();
              available.push(room);
          }

          if(!available.empty()){
              int room=available.top();
              available.pop();
              roomused[room]++;
              used.push({end,room});
          }else{
              auto meeting=used.top();
              used.pop();
              roomused[meeting.second]++;
              used.push({meeting.first+time,meeting.second});
          }

        }
        int value=*max_element(roomused.begin(),roomused.end());
        for(int i=0;i<n;i++){
            // cout<<roomused[i]<<" ";
            if(roomused[i]==value){
                return i;
            }
        }
        return -1;
        
    }
};