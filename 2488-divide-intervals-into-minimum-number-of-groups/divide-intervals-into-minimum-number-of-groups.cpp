class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int,int> mp;
        for(auto j: intervals)
        {
            mp[j[0]]++;
            mp[j[1]+1]--;
        }
        int maxi=0,count=0;
        for(auto j: mp)
        {
            count+=j.second;
            maxi=max(maxi,count);
        }
        return maxi;
    }
};