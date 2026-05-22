class Solution {
public:
    int binarysearch(vector<int>&nums,int start,int end,int target){
        int mid=start+(end-start)/2;
        while(start<=end){
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
            mid=start+(end-start)/2;
        }
        return -1;
    }
    int pivot(vector<int>&nums){
        int start=0;
        int end=nums.size()-1;
        int mid=start+(end-start)/2;
        while(start<end){
            if(nums[mid]>=nums[0]){
                start=mid+1;
            }
            else if(nums[mid]<nums[0]){
                end=mid;
            }
            mid=start+(end-start)/2;
        }
        return end;
    }
    int search(vector<int>& nums, int target) {
     
        int value=pivot(nums);
        if(target==nums[value]){
            return value;
        }
       else if(target>=nums[0]){
            return binarysearch(nums,0,value-1,target);
        }
        else{
              return binarysearch(nums,value,nums.size()-1,target);
        }
    }
};