class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int start = 0;
        int ans = 0;
        for(auto j: requests)
        {
            ans += abs(j-start);
            start = j;
        }
        return ans;
    }
};