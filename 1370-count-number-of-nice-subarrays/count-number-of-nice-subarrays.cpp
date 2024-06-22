class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> prefix(nums.size(),0);
        for(int i=0;i<nums.size();i++){
              if(i == 0){
                if(nums[i] % 2)prefix[i]++;
                continue;
              }
              prefix[i]=prefix[i-1]+(nums[i] % 2);
        }
     
        
        map<int,int> mp;
        mp[0]++;
        int ans=0;
        for(int i=0;i<nums.size();i++){
             ans+=mp[prefix[i]-k];
             mp[prefix[i]]++;
        }
        return ans;
    }
};