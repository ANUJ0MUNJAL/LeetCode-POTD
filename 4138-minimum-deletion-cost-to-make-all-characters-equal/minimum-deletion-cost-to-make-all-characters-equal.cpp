class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        map<char,long long> mp;
        long long total = 0;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]] += cost[i];
            total += cost[i];
        }
        long long mini = 1e18;
        for(auto j: mp)
        {
           mini = min(mini,total - j.second);
        }
        return mini;
    }
};