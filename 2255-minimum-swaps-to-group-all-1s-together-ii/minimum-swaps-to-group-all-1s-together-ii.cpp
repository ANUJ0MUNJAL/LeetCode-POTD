class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int count=0,swaps=0;
        for(int i=0;i<nums.size();i++){
             if(nums[i]==1)count++;
        }
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
             if(nums[i]==0)swaps++;
             if(i-count+1 >= 0 and (i-count+1) < nums.size()){
                 mini=min(mini,swaps);
                if(nums[i-count+1]==0)swaps--;
             }
           
        }
        swaps=0;
         count=nums.size()-count;
        for(int i=0;i<nums.size();i++){
             if(nums[i]==1)swaps++;
             if(i-count+1>=0 and (i-count+1) < nums.size()){
                mini=min(mini,swaps);
                if(nums[i-count+1]==1)swaps--;
             }
               
        }
        return mini;
    }
};