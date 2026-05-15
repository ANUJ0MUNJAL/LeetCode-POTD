class Solution {
public:
    int pivot(vector<int>&nums){
         int start=0;
        int end=nums.size()-1;
        int mid=start+(end-start)/2;
        int ans=INT_MIN;
        while(start<=end){
           
          if(nums[mid]>=nums[0]){
                start=mid+1;
            }
           else if(nums[mid]<nums[0]){
               ans=nums[mid];
               end=mid-1;
           }
           mid=start+(end-start)/2;
        }
        return ans;
    }
    int findMin(vector<int>& nums) {
        if(nums.size()==1)
           return nums[0];
       int p=pivot(nums);
       if(p==INT_MIN)
          return nums[0];
        else
           return p;
    }
};