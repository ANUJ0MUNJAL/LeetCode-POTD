class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int count = 0;
        for(int i=0;i<nums.size();i++)
        {
            double odd = 0 , even = 0;
            for(int j=i;j<nums.size();j++)
            {
                   if(nums[j] & 1)odd++;
                   else even++;
                   
                   

                   if(odd >= 1 and even*b <= odd*a)count++;
            }
            
        }
        return count;
    }
};