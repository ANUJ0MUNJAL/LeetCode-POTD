class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        sort(lights.begin(),lights.end());
        int ans = 0;

        for(int i=0;i<arrivalTime.size();i++)
        {
            int val = arrivalTime[i] % period;
            if(lights[lights.size()-1] <= val)
            {
                ans =max(ans, (period - val));
            }
        }
        return ans;
    }
};