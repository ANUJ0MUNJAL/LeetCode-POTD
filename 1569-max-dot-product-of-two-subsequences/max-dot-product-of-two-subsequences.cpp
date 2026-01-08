class Solution {
public:
  
    int solve(vector<int>&nums1,vector<int>&nums2,int index1,int index2,vector<vector<int>>&dp){
        if(index2>=nums2.size() or index1>=nums1.size()){
            return 0;
        }
        if(dp[index1][index2]!=-1){
            return dp[index1][index2];
        }
        int include=INT_MIN;
        if(index1<nums1.size() and index2<nums2.size()){
            include=nums1[index1]*nums2[index2]+solve(nums1,nums2,index1+1,index2+1,dp);
        }
        int exclude=max({solve(nums1,nums2,index1,index2+1,dp),solve(nums1,nums2,index1+1,index2,dp)});
        return dp[index1][index2]=max(include,exclude);
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size(),vector<int>(nums2.size(),-1));
        int ans=solve(nums1,nums2,0,0,dp);
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        if(ans==0){
           if(nums1[nums1.size()-1]<0){
               auto idx=upper_bound(nums2.begin(),nums2.end(),-1)-nums2.begin();
               return nums1[nums1.size()-1]*nums2[idx];
           }
           else{
            auto idx=upper_bound(nums1.begin(),nums1.end(),-1)-nums1.begin();
               return nums2[nums2.size()-1]*nums1[idx];
           }
        }
        return ans;
    }
};