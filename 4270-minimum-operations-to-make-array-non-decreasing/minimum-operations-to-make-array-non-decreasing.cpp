class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long sum = 0;
        long long maxi = nums[0];
        for(int i=1;i<nums.size();i++)
        {
           if(nums[i] + sum >= maxi)
           {
               maxi = nums[i] + sum;
           }else{
               long long val = nums[i] + sum;
               long long temp = maxi - val;
               sum += temp;
           }
        }
        return sum;
    }
};