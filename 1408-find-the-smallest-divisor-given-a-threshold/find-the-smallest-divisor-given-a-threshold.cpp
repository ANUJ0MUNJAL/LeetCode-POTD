class Solution {
public:
    bool solve(vector<int>&arr,int val,int total)
    {
          long long ans = 0;
          for(int i=0;i<arr.size();i++)
          {
            ans+=(arr[i]+val-1)/val;
            if(ans > total)return false;
          }
          return true;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
         int start = 1;
         int end = *max_element(nums.begin(),nums.end());
         int ans=-1;
         while(start <= end)
         {
             int mid = start+(end-start)/2;
             if(solve(nums,mid,threshold))
             {
                ans=mid;
                end=mid-1;
             }else{
                start=mid+1;
             }
         }
         return ans;
    }
};