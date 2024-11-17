class Solution {
public:
    bool solve(vector<int>&nums,vector<vector<int>>&queries,int k)
    {     cout<<k<<"\n";
          vector<int> arr(nums.size()+2,0);
          int count=0;
        for(auto j: queries)
        {
           
             arr[j[0] - 1 + 1]+=j[2];
             arr[j[1] + 1]-=j[2];
             count++;
             if(count == k)break;
        }
       
        vector<int> prefix(arr.size(),0);
        for(int i=0;i<arr.size();i++)
        {
             if(i == 0)
             {
                 prefix[i]=arr[i];
             }else{
                prefix[i]=prefix[i-1]+arr[i];
             }
        }
        
        for(int i=0;i<nums.size();i++)
        {
             int val = prefix[i];
          
             if(nums[i] > abs(val))return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
         int start=1;
         int val = *max_element(nums.begin(),nums.end());
         if(val == 0)return 0;
         int end = queries.size();
         int ans =-1;
         while(start <= end)
         {
             int mid = start+(end-start)/2;
             if(solve(nums,queries,mid))
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