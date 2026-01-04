class Solution {
public:
    int count(int value)
    {
        int sum = 0;
        int count = 0;
        for(int i=1;i<=sqrt(value);i++)
        {
            if(value % i == 0)
            {
                sum += i;
                count++;
                int temp = value / i;
                if(temp != i)
                {
                    sum += temp;
                    count++;
                    
                }
                if(count > 4)return 0;
            }
        }
        return count == 4 ? sum : 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++)
        {
           int value = count(nums[i]);
           sum += value;
        }
        return sum;
    }
};