class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
         vector<int> next(nums.size());
         stack<int> st;
         st.push(-1);

         for(int i = nums.size()-1;i >= 0;i--)
         {
            while(st.top() != -1 and nums[st.top()] < nums[i])st.pop();

            next[i] = st.top(); 

            st.push(i);
         }
         
         vector<int> left(nums.size(),0);
         stack<int> st1;
         st1.push(-1);
         for(int i=0;i<nums.size();i++)
         {
            while(st.top() != -1 and nums[st.top()] < nums[i])st.pop();
            left[i] = st.top();
            st.push(i);
         }
        //  for(auto j: left)cout<<j<<" ";
        long long count = 0;
         for(int i=0;i<next.size();i++)
         {
            if(next[i] == -1)continue;
            int val = next[i] - i + 1;
            if(val >= 3)count++;
         }
         for(int i=left.size()-1;i>=0;i--)
         {
            if(left[i] == -1)continue;
            int val = i - left[i] + 1;
            if(val >= 3)count++;
         }
         return count;


          return 0;



    }
};