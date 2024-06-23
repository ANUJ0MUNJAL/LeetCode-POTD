class Solution {
public:
    double minimumAverage(vector<int>& nums) {
         sort(nums.begin(),nums.end());
         int i=0;
         int j=nums.size()-1;
         double mini=INT_MAX;
         while(i < j){
              double val=(nums[i]+nums[j])/2.0;
              mini=min(mini,val);
              i++;
              j--;
         }
         return mini;
    }
};