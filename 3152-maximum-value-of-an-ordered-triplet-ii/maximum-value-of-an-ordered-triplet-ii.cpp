class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        long long diff = 0;
        long long maxi = 0;

        for(auto j: nums){
            ans = max(ans,diff*j);
            diff = max(diff,maxi - j);
            maxi = max(maxi,1LL*j);
        }
        return ans;
    }
};