class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int> st(nums.begin(),nums.end());
        int val = k;
        while(true)
        {
            if(st.find(val) == st.end()) return val;
            val += k;
        }
        return -1;

    }
};