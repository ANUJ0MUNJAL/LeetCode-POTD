class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        long long a = 0 , b = 0;

        int i = 0;
        
        while(i+1 < nums.size() and nums[i+1] > nums[i])
        {
            a+=nums[i];
            i++;
        }
        a+=nums[i];
        while(i < nums.size())
        {
            b+=nums[i];
            i++;
        }
        if(a > b)return 0;
        else if(a < b)return 1;
         return -1;

    }
};