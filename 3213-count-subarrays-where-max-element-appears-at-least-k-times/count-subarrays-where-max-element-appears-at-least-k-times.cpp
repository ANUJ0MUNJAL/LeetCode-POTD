class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        map<int,int> mp;
        int start=0;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
        }
        long long int count=0;
        for(int i=0;i<nums.size();i++){
           mp[nums[i]]++;
            if(mp[maxi]>=k){
                count+=nums.size()-i;
                
                while(mp[maxi]>=k){
                    mp[nums[start]]--;
                    start++;
                    if(mp[maxi]>=k)
                      count+=nums.size()-i;
                        
                }
            }
            
        }
        return count;
        
    }
};