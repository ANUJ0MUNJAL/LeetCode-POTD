class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int mini=-1,maxi=-1,bad=-1;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] < minK || nums[i] > maxK) bad=i;
             if(nums[i]==minK) mini=i;
             if(nums[i]==maxK) maxi=i;
            ans+=max(0,min(mini,maxi)-bad);
        }
        return ans;
    }
};