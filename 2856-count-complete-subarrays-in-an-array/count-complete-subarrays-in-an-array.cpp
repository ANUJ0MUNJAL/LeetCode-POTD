class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        
        map<int,int> mp;
        int slow = 0;
        int ans = 0;
        set<int> st(nums.begin(),nums.end());
       
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            while(slow <= i and mp.size() >= st.size()){
                ans+=nums.size()-i;
                mp[nums[slow]]--;
                if(mp[nums[slow]] == 0)mp.erase(nums[slow]);
                slow++;
            }
        }
        return ans;
    }
};