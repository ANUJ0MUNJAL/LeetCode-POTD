class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count = 0;
       // 2 2 3 4
       vector<int> temp;
       for(auto j: nums)if(j != 0)temp.push_back(j);
       nums= temp;
        if(nums.size() < 3)return 0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j = i+1;j<nums.size();j++)
            {
                int val = nums[i] + nums[j];
                auto itr = lower_bound(nums.begin(),nums.end(),val)-nums.begin();

                count+=(itr - j - 1);
            }
          
        }
        return count <= 0 ? 0 : count;

    }
};