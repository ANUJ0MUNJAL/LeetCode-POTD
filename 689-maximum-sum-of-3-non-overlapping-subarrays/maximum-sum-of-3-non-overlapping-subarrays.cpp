class Solution {
public:

  
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> left(nums.size(),0);
        vector<int> sum(nums.size(),0);
        for(int i=0;i<nums.size();i++)
        {
            if(i == 0)sum[i]=nums[i];
            else sum[i]+=sum[i-1]+nums[i];
        }
        int total = 0;
        for(int i=k;i<nums.size();i++)
        {
             if(i == k)
             {
                 left[i]=i-k;
                 total = sum[i-1];
                 continue;
             }
         
             if((sum[i - 1] - sum[i - k - 1])> total)
             {
                
                 left[i]=i-k;
                 total = sum[i-1]-sum[i - k - 1];
             }else{
                left[i]=left[i-1];
             }
        }
        vector<int> right(nums.size(),nums.size()-k);
        total = 0;
        for(int i = nums.size()-k-1;i>=0;i--)
        {
            if(sum[i+k] - sum[i] >= total)
            {
                right[i]=i+1;
                total = sum[i+k]-sum[i];
            }else{
                right[i]=right[i+1];
            }
        }
      
        total = 0;
        int maxi = 0;
        vector<int> ans;
        for(int i=k;i<=nums.size()-2*k;i++)
        {
           int l= left[i];
           int r = right[i+k-1];
           

           int total = 0;
            if(l-1 < 0) total+=sum[l+k-1];
            else total+=sum[l+k-1]-sum[l-1];

            
            cout<<total<<" ";
            total+=sum[i+k-1];
            total-=sum[i-1];
            cout<<total<<" ";
        //    cout<<r<<endl;
            total+=sum[r+k-1];
            total-=sum[r-1];
          
            cout<<total<<endl;
            if(total > maxi)
            {
                ans = {l,i,r};
                maxi=total;
            }
        }
        return ans;

    }
};