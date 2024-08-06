class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int val=nums[0];
        for(auto j: nums)val&=j;
        if(val != 0)return 1;
        int count=0;
        for(int i=0;i<nums.size();){
              int val=INT_MAX;
              while(i < nums.size() and val!=0){
                   val&=nums[i];
                   i++;
              }
              if(val==0)
              count++;
        }
        return count;

    }
};