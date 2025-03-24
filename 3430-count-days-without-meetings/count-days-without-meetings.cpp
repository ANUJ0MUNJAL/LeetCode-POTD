class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int ans=max(0,meetings[0][0]-0-1);
        
        int maxi=meetings[0][1];
        for(int i=1;i<meetings.size();i++){
            maxi=max(maxi,meetings[i-1][1]);
         
            ans+=max(0,meetings[i][0]-maxi-1);
        }
        maxi=max(maxi,meetings[meetings.size()-1][1]);
        ans+=max(0,days-maxi);
        return ans;
    }
};