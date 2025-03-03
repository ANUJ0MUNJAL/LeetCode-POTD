class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;

        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] < pivot)ans.push_back(nums[i]);
            else if(nums[i] == pivot)mp[nums[i]]++;
        }
        for(int i=0;i<mp[pivot];i++)
        {
            ans.push_back(pivot);
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] > pivot)ans.push_back(nums[i]);
        }
        return ans;
    }
};