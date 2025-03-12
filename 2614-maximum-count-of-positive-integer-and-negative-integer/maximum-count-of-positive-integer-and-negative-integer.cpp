class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos=0,neg=0;
        for(auto j: nums)
        {
            if(j < 0)neg++;
            else if(j > 0)pos++;
        }
        return max(pos,neg);
    }
};