class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            int val = nums[i];
            vector<int> temp;
            while(val)
            {
                temp.push_back(val%10);
                val/=10;
            }
            reverse(temp.begin(),temp.end());
            for(auto j: temp)ans.push_back(j);
        }
        return ans;
    }
};