class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini  = INT_MAX;
        for(auto j: nums)mini = min(mini,j);
        return mini;
    }
};