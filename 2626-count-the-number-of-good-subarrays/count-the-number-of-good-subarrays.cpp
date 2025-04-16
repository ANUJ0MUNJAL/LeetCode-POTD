class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans = 0;
        int slow =0,count=0;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int val = mp[nums[i]];
            count-=(val*(val-1))/2;
            mp[nums[i]]++;
            val = mp[nums[i]];
            count+=(val*(val-1))/2;

            while(slow <= i and count >= k){
               
                ans+=(nums.size()-i);
                 int val = mp[nums[slow]];
            
            count-=(val*(val-1))/2;
          
            mp[nums[slow]]--;
            val = mp[nums[slow]];
            
            count+=(val*(val-1))/2;
                
                if(mp[nums[slow]] == 0)
                  mp.erase(mp[nums[slow]]);
                slow++;
            }
        }
        return ans;
    }
};