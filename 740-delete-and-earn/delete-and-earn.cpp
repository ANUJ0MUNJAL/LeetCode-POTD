class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> mp,dp;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
              mp[nums[i]]++;
        }
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
              auto itr=dp.lower_bound(nums[i]-1);
              int val=0;
              if(itr != dp.begin()){
                  itr--;
                  val=itr->second;
              }
              dp[nums[i]]=max({dp[nums[i]],mp[nums[i]]*nums[i]+ val,maxi});
              maxi=max(maxi,dp[nums[i]]);
        }
        return maxi;
    }
};