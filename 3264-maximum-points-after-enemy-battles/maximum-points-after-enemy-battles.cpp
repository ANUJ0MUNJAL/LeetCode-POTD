class Solution {
public:
    long long maximumPoints(vector<int>& nums, int val) {
         sort(nums.begin(),nums.end());
        if(nums.size()==1){
            return val/nums[0];
        }
        if(val < nums[0]){
            return 0;
        }
        long long ans=val;
        for(int i=1;i<nums.size();i++){
            ans+=nums[i];
        }
        return ans/nums[0];
    }
};