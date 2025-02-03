class Solution {
public:
    
    
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxi=0,count=0,countb=0;
       for(int i=0;i<nums.size();i++){
           int prev=nums[i];
           int prev1=nums[i];
           count=1,countb=1;
           for(int j=i+1;j<nums.size();j++){
               if(nums[j] > prev){
                   count++;
                   prev=nums[j];
                    }
             else{
                 break;
             }
              
           }
           maxi=max(maxi,count);
       }
         for(int i=0;i<nums.size();i++){
           int prev=nums[i];
           int prev1=nums[i];
           count=1,countb=1;
           for(int j=i+1;j<nums.size();j++){
               if(nums[j] < prev){
                   count++;
                   prev=nums[j];
                    }
             else{
                 break;
             }
              
           }
           maxi=max(maxi,count);
       }
       return maxi;
    }
};