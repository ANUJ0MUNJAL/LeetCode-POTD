class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        set<int>st;
        sort(nums.begin(),nums.end());
        int prev = INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            int val = max(prev+1,nums[i]-k);
            if(val <= nums[i]+k)
            {
                st.insert(val);
                prev=val;
            }
        }
        return st.size();
    }
};