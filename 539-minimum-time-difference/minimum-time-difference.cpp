class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> temp;
        for(int i=0;i<timePoints.size();i++)
        {
            temp.push_back(stoi(timePoints[i].substr(0,2))*60+stoi(timePoints[i].substr(3,2)));

        }
        sort(temp.begin(),temp.end());
        int ans=INT_MAX;
        for(int i=1;i<temp.size();i++)
        {
            ans=min(ans,temp[i]-temp[i-1]);
        }
        ans=min(ans,temp[0]-temp[temp.size()-1]+24*60);
        return ans;
    }
};