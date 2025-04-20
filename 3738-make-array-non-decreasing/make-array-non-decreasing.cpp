class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
       int maxi = 0;
       int count = 0;
       
        for(int i=0;i<nums.size();i++){
            
            if(i == 0)count++;
            else{
                if(nums[i] >= maxi)count++;
            }
            maxi = max(maxi,nums[i]);
        }
    return count;
      
    }
};