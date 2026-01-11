class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int count = 0;
        for(int i=0;i<nums.size();i++)
        {
            int sum = 0;
            set<int> st;
            for(int j=i;j<nums.size();j++)
            {
                sum+=nums[j];
                st.insert(nums[j]);
                if(st.find(sum) != st.end())count++;

            }
        }
        return count;
    }
};