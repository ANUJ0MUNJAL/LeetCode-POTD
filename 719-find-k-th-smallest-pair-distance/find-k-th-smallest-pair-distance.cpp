class Solution {
public:
    int find(vector<int>&nums,int val,int k)
    {
             int count=0;
             for(int i=1;i<nums.size();i++)
             {
                  int value=nums[i]-val;
                  int index=lower_bound(nums.begin(),nums.end(),value)-nums.begin();

                    count+=(i-index);

                 
             }
             cout<<count<<" "<<val<<"\n";
             return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
         sort(nums.begin(),nums.end());
         int start=0;
         int end=nums[nums.size()-1]-nums[0];
         int ans=-1;
         while(start <= end)
         {
            int mid=start+(end-start)/2;
            if(find(nums,mid,k) >= k){
                ans=mid;
                end=mid-1;
            }else{
               
               start=mid+1;
            }
         }           
         return ans;
    }
};