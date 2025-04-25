class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        vector<long long> prefix(nums.size());
        for(int i=0;i<nums.size();i++){
            if(i==0){
                prefix[i]=((nums[i] % modulo)==k);
            }else{
                int val=nums[i]%modulo;
                prefix[i]=prefix[i-1]+(val==k);
            }
        }
        map<int,int> mp;
        mp[0]=1;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
             ans+=mp[(prefix[i] % modulo - k+modulo)%modulo];
             mp[prefix[i]%modulo]++;
        }
        return ans;
    }
};