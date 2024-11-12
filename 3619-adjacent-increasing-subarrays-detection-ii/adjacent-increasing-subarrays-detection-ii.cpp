class Solution {
public:
    bool solve(vector<int>&prefix,int mid,vector<int>&arr)
    {
        cout<<mid<<"\n";
         for(int i=2*mid -1; i <prefix.size();i++)
         {
              
              if(i - 2*mid < 0)
              {
                
                     int val = prefix[i];
                    
                     if(arr[i-mid+1] <= arr[i-mid])val--;
                     
                     if(val == 0)return true;
                 
              }else{
                  int val = prefix[i] - prefix[i - 2*mid +1];
                  if(arr[i-mid+1] <= arr[i-mid])val--;
                  if(val == 0)return true;
                  
              }
              
         }
         return false;
    }
    int maxIncreasingSubarrays(vector<int>& nums) {
        int start=1;
        int end=nums.size()/2;
        vector<int> prefix(nums.size(),0);
        for(int i=0;i<nums.size();i++)
        {
             if(i == 0)
             {
                prefix[i]=0;
             }else{
                 if(nums[i] <= nums[i-1])
                 {
                     prefix[i]++;
                     
                 }
                 prefix[i]+=prefix[i-1];
             }

        }
        int ans=1;
        while(start <= end)
        {
             int mid = start+(end-start)/2;
             if(solve(prefix,mid,nums))
             {
                 ans=mid;
                 start=mid+1;
             }else{
                end=mid-1;
             }
        }
        return ans;
    }
};