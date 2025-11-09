class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for(auto j: mp)
        {
             vector<int> temp = j.second;

             for(int i=0;i<temp.size();i++)
             {
                 if(i+2 < temp.size())
                 {
                    ans = min(ans,2*(temp[i+2] - temp[i]));
                 }
             }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};