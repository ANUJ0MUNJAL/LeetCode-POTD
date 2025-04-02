class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxi = 0;
        long long maxidiff = 0;
        long long ans = 0;

        for(auto j: nums){
            ans = max(ans,(maxidiff)*j);
            maxidiff = max(maxidiff,maxi - j);
            maxi = max(maxi,1LL*j);
        }
        return ans;
    }
};