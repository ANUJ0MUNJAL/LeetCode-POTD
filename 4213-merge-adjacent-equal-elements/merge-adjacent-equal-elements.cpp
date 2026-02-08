class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long> st;

        for(int i=0;i<nums.size();i++)
        {
            long long value = nums[i];
            while(!st.empty() and st.top() == value)
            {
                st.pop();
                value = value*2;
            }
            st.push(value);
        }
        vector<long long> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};