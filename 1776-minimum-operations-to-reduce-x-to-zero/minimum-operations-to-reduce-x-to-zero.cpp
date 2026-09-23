class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        sum=sum-x;
        if(sum==0){
            return nums.size();
        }
        int sum1=0;
        int ans=0;
        int i=0;
        for(int j=0;j<nums.size();j++){
            sum1+=nums[j];
            while(i<nums.size() and sum1>sum){
                sum1-=nums[i++];
            }
            if(sum==sum1){
                ans=max(ans,j-i+1);
            }
        }
        if(ans==0)
          return -1;
          return nums.size()-ans;
    }
};