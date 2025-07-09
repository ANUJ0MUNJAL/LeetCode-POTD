class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> gaps(startTime.size()+1,0);
        gaps[0] = startTime[0];
        gaps[gaps.size()-1] = eventTime - endTime[endTime.size()-1];
        for(int i=1;i<startTime.size();i++)
        {
             gaps[i] = startTime[i] - endTime[i-1];
        }
        vector<int> prefix(gaps.size(),0);
        for(int i=0;i<gaps.size();i++)
        {
            if(i == 0)prefix[i] = gaps[i];
            else prefix[i]+=gaps[i]+prefix[i-1];
        }
        int ans = 0;
        for(int i = k;i<prefix.size();i++)
        {
            if(i == k)ans=max(ans,prefix[i]);
            else ans = max(ans,prefix[i] - prefix[i-k-1]);
        }
        return ans;
    }
};