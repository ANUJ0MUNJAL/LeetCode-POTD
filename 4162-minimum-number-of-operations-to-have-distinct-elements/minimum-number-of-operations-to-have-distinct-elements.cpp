class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> mp;
        int index = -1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(mp.count(nums[i]))
            {
                index = i;
                break;
            }
            mp[nums[i]]++;
        }
        if(index == -1)return 0;
        return (index+3)/3;

    }
};