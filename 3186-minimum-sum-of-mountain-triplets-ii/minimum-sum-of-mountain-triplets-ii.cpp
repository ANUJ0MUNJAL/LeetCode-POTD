class Solution {
public:
    int minimumSum(vector<int>& nums) {
       vector<int> left(nums.size(),nums[0]);
       for(int i=1;i<nums.size();i++)
       {
         left[i]=min(left[i-1],nums[i-1]);
       }
       vector<int> right(nums.size(),nums[nums.size()-1]);
       for(int i=nums.size()-2;i>=0;i--)
       {
          right[i]=min(right[i+1],nums[i+1]);
       }
       int ans=INT_MAX;
       for(int i=1;i<nums.size()-1;i++)
       {
            if(left[i] < nums[i] and nums[i] > right[i])
            {
                  ans=min(ans,left[i]+nums[i]+right[i]);
            }
       }
       return ans==INT_MAX?-1:ans;
    }
};