class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int sum = 0;
        int index = 0;
        for(auto j : nums)
        {
            if(index & 1)sum-=j;
            else sum+=j;
            index++;
        }
        return sum;
    }
};