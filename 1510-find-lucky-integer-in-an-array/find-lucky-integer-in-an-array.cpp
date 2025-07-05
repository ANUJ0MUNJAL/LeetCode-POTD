class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int> mp;
        for(auto j: arr)mp[j]++;
        int ans = -1;
        for(auto j: mp)
        {
            if(j.first == j.second)
            {
                ans = j.first;
            }
        }
        return ans;
    }
};