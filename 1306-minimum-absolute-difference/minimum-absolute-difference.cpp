class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        map<int,vector<vector<int>>> mp;
        sort(arr.begin(),arr.end());
        int ans = INT_MAX;
        for(int i=1;i<arr.size();i++)
        {
            ans = min(ans,arr[i] - arr[i-1]);
            mp[arr[i] - arr[i-1]].push_back({arr[i-1],arr[i]});
        }

        return mp[ans];
    }
};