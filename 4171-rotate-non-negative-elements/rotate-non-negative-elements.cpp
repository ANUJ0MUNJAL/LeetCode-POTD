class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> pos;
        for(auto j: nums)
        {
            if(j >= 0)pos.push_back(j);
        }
        vector<int> temp(pos.size());
        if(pos.size() == 0)return nums;
        k %= pos.size();
        for(int i=0;i<pos.size();i++)
        {
            temp[((i-k) + pos.size())%pos.size()] = pos[i];
        }

        for(auto j: temp)
        {
            cout<<j<<"--";
        }
        
        int j = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] >= 0)
            {
                nums[i] = temp[j];
                j++;
            }
        }
        return nums;
    }
};