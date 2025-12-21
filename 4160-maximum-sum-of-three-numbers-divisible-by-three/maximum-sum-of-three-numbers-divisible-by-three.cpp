class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int,vector<int>>mp;
        for(auto j: nums)mp[j % 3].push_back(j);

        for(int i=0;i<=2;i++)
        {
            sort(mp[i].begin(),mp[i].end());
        }
        int ans = 0;
        for(int i=0;i<=2;i++)
        {
            if(mp[i].size() >= 3)
           ans = max(ans,mp[i][mp[i].size()-1]+ mp[i][mp[i].size()-2] +  mp[i][mp[i].size()-3]);
        }
       
        if(mp[0].size() >= 1 and mp[1].size() >= 1 and mp[2].size() >= 1)
        {
            ans =max(ans,mp[0][mp[0].size()-1]+ mp[1][mp[1].size()-1] +  mp[2][mp[2].size()-1]);
        }

        return ans;

    }
};