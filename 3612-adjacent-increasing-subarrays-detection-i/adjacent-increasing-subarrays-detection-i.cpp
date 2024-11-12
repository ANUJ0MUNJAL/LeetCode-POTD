class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        
        
        for(int i=0;i<=nums.size()-2*k;i++)
        {
             bool flag=true;
             int j=i+1;
              for(;j<i+k;j++)
              {
                  if(nums[j] <= nums[j-1])
                  {
                    flag=false;
                    break;
                  }
              }
            
            //   if(nums[j] >= nums[j-1])flag=false;
              if(!flag)continue;
              int val = j+k-1;
              
              j++;
             
            
              for(;j<=val;j++)
              {
                if(nums[j] <= nums[j-1])
                  {
                    flag=false;
                    break;
                  }
              }
             
              if(!flag)
              {
                continue;
              }else{
                return true;
              }


        }
        return false;
    }
};