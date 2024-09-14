class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        set<int> st;
        st.insert(nums[0]);
        int val=nums[0];
        for(int i=1;i<nums.size();i++)
        {
             set<int> st1;
             st1.insert(nums[i]);
             val=max(val,nums[i]);
             for(auto j: st)
             {
                val=max(val,j&nums[i]);
                st1.insert(j&nums[i]);
             }
            //  for(auto j: st)
            //  {
            //     cout<<j<<" ";
            //  }
            //  cout<<"\n";
             st=st1;
        }
       
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