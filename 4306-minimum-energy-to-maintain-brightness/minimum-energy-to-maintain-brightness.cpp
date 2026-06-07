class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        vector<int> prev = intervals[0];
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0] <= prev[1])
            {
                prev[1] = max(prev[1],intervals[i][1]);
            }else{
                ans.push_back(prev);
                prev = intervals[i];
            }
        }
        ans.push_back(prev);
        long long total = 0;
        for(int i=0;i<ans.size();i++)
        {
            total += (ans[i][1] - ans[i][0]) + 1;
        }
        long long temp = (brightness+2)/3;
        return temp*total;
    }
};