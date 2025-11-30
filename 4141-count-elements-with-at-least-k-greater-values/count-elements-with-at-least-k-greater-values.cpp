class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int count = 0;

        for(int i=0;i<nums.size();i++)
        {
            auto itr = upper_bound(nums.begin(),nums.end(),nums[i]);

            if(nums.end() - itr >= k)count++;
        }
        return count;
    }
};