class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        set<int> st;
        st.insert(nums[0]);
        int val=*max_element(nums.begin(),nums.end());
        
       
        int value = INT_MAX;
        int start=0;
        int ans=0;
        for(int i=0;i<nums.size();)
        {
            value = INT_MAX;
            while(i<nums.size() and value >= val)
            {
                value&=nums[i];
                i++;
            }
            if(i >= nums.size() and value >=val)
            {
                  ans=max(ans,i-start);
            }
            ans=max(ans,i-start-1);
            start=i;
            
        }
      
      
        return ans;

        
    }
};