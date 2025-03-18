class Solution {
public:
    bool check(vector<int>&bits)
    {
        for(int i=0;i<bits.size();i++)
        {
            if(bits[i] > 1)return false;
        }
        return true;
    }
    int longestNiceSubarray(vector<int>& nums) {
       int ans = 0;
       vector<int> bits(31,0);
       int slow = 0;
       for(int i=0;i<nums.size();i++)
       {
           for(int j=0;j<31;j++)
           {
                int mask = 1 << j;
                if(mask & nums[i])bits[j]++;
           }

           while(!check(bits)){
            
               for(int j=0;j<31;j++)
               {
                   int mask = 1 << j;
                   if(mask & nums[slow])bits[j]--;
               }
               slow++;
           }
           ans = max(ans,i-slow+1);
       }
       return ans;
     
       
    }
};