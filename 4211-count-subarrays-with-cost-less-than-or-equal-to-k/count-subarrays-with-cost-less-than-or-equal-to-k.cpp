class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
       multiset<long long> st;
       int slow = 0;
       long long ans = 0;
       for(int i=0;i<nums.size();i++)
       {
          st.insert(nums[i]);
          long long mini = *st.begin();
          long long maxi = *st.rbegin();
          long long len = i - slow + 1;
          long long val = (maxi-mini)*len;
          while(!st.empty() and val > k)
          {
              st.erase(st.find(nums[slow++]));
              if(st.size() >= 1)
              val = (*st.rbegin() - *st.begin())*(i-slow+1);
          }
          ans+=(i-slow+1);
       }
       return ans;
    }
};