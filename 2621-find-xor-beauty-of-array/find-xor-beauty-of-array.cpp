class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int val = 0;
        for(auto j: nums)val^=j;
        return val;
    }
};