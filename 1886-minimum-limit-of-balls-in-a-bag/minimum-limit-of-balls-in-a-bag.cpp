class Solution {
public:
    bool poss(int val,int maxi,vector<int>&nums)
    {
        int count=0;
        int left = 0;
        for(int i=0;i<nums.size();i++)
        {
            count+=(nums[i]+val-1)/val;
            count--;
        }
        
        return count <= maxi;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
         int start=1;
         int end=1e9;
         int ans = -1;
         while(start <= end)
         {
            int mid = start+(end-start)/2;
            if(poss(mid,maxOperations,nums))
            {
                ans = mid;
                end=mid-1;
            }else{
                start=mid+1;
            }

         }
         return ans;
    }
};