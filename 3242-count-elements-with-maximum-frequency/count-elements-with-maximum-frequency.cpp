class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
         map<int,int> mp;
        
         int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
             mp[nums[i]]++;
            
        }
        for(auto j: mp){
            maxi=max(maxi,j.second);
        }
        int ans=0;
        for(auto j: mp){
            if(j.second==maxi){
                ans+=j.second;
            }
        }
        return ans;
        
        
    }
};