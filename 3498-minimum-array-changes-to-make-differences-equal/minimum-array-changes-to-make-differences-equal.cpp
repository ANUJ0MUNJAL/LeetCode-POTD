class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        map<int,int> mp,pos;
        for(int i=0;i<nums.size()/2;i++){
              int val=abs(nums[i]-nums[nums.size()-i-1]);
              mp[val]++;
              int maxi=max({k-nums[i],nums[i]-0,nums[nums.size()-i-1]-0,k-nums[nums.size()-i-1]});
              pos[maxi]++;
        }
         int total=nums.size()/2;
         int two=0;
         int ans=INT_MAX;
        for(int i=0;i<=k;i++){
           ans=min(ans,2*two+total-mp[i]);
           total-=pos[i];
           two+=pos[i];
        }
        return ans;
        
    }
};