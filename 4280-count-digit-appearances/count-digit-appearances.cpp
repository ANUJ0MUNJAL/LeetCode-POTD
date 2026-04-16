class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int count = 0;
        for(auto j: nums)
        {
            int val = j;
            while(val != 0)
            {
                if(val % 10 == digit)count++;
                val/=10;
            }
        }
        return count;
    }
};