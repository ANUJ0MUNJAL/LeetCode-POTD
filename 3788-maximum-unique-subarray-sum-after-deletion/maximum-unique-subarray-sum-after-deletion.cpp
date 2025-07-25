class Solution {
public:
    int maxSum(vector<int>& nums) {
        vector<int> temp;
        set<int> st;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] < 0)continue;
            else{
               if(st.find(nums[i])!=st.end())continue;
               temp.push_back(nums[i]);
               st.insert(nums[i]);
            }
        }
        if(temp.size()==0)
        {
            sort(nums.begin(),nums.end());
            return nums[nums.size()-1];
        }
        int maxi = 0;
        maxi = accumulate(temp.begin(),temp.end(),0);
        return maxi;
    }
};