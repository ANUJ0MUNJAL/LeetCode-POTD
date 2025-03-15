class Solution {
public:
    bool possible(vector<int>&arr,int value,int k)
    {
        int count = 0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i] <= value)
            {
                count++;
                i++;
            }
            if(count >= k)return true;
        }
        return false;
    }
    int minCapability(vector<int>& nums, int k) {
         int start = 0;
         int end = 1e9;
         int ans = end;
         while(start <= end)
         {
            int mid = start+(end-start)/2;
            if(possible(nums,mid,k))
            {
                ans = mid;
                end = mid-1;
            }else{
                start=mid+1;
            }
         }
         return ans;
    }
};