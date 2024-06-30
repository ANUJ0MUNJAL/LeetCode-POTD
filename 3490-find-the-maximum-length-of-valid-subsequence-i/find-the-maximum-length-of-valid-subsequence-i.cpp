class Solution {
public:
       int maximumLength(vector<int>& nums) {
          int count=0;
          int maxi=INT_MIN;
          bool flag=true;
          for(int i=0;i<nums.size();i++){
              if(!flag and nums[i] % 2 == 0){
                   flag=true;
                   count++;
              }else if(flag and nums[i] % 2 != 0){
                   flag=false;
                   count++;
              }
          }
          maxi=max(maxi,count);
            flag=false;
           count=0;
          for(int i=0;i<nums.size();i++){
              if(!flag and nums[i] % 2 == 0){
                   flag=true;
                   count++;
              }else if(flag and nums[i] % 2 != 0){
                   flag=false;
                   count++;
              }
          }
          maxi=max(maxi,count);
             flag=false;
           count=0;
          for(int i=0;i<nums.size();i++){
              if(nums[i] % 2 == 0){
                 count++;
              }
          }
          maxi=max(maxi,count);

          flag=false;
           count=0;
          for(int i=0;i<nums.size();i++){
              if(nums[i] % 2 != 0){
                 count++;
              }
          }
          maxi=max(maxi,count);
          return maxi;
    }
};