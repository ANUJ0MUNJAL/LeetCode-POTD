class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        int ans=1;
        sort(coins.begin(),coins.end());
        for(auto j: coins)
        {
            if(j > ans)break;
            ans+=j;
        }
        return ans;
    }
};