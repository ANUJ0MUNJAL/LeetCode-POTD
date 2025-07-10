class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        
         vector<int> gaps(startTime.size()+1,0);
        gaps[0] = startTime[0];
        gaps[gaps.size()-1] = eventTime - endTime[endTime.size()-1];
        for(int i=1;i<startTime.size();i++)
        {
             gaps[i] = startTime[i] - endTime[i-1];
        }
        // 0 2 3 1 0
        vector<int> right(gaps.size(),0);
        for(int i=gaps.size()-2;i>=0;i--){
  
             right[i] = max(gaps[i+1],right[i+1]);
        }
       int left = 0,maxi = 0;
         for(int i=1;i<gaps.size();i++){
            int len = endTime[i-1] - startTime[i-1];
            if(left >= len or right[i] >= len)
            {
                int merged = gaps[i-1]+gaps[i]+len;
                maxi = max(maxi,merged);
            }
            maxi = max(maxi,gaps[i-1]+gaps[i]);
            left = max(left,gaps[i-1]);

        }
        return maxi;
        
    }
};