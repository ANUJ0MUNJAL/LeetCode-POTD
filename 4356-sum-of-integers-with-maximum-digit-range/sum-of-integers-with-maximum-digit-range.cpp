class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++)
        {
             string temp = to_string(nums[i]);
             sort(temp.begin(),temp.end());
             int value = temp[temp.length()-1]-temp[0];

             mp[value].push_back(i);
        }
        int ans = 0;
        for(auto j: mp)
        {
            ans = max(ans,j.first);
        }
        int sum = 0;
        for(auto j: mp[ans])
        {
          sum += nums[j];
        }
        return sum;
    }
};