class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int,vector<int>> mp;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                mp[i+j].push_back(mat[i][j]);
            }
        }
        vector<int> ans;
        for(auto j: mp)
        {
            if(j.first & 1)
            {
                for(int i=0;i<j.second.size();i++)
                {
                    ans.push_back(mp[j.first][i]);
                }
            }else{
                for(int i=j.second.size()-1;i>=0;i--)
                {
                    ans.push_back(mp[j.first][i]);
                }
            }
        }
        return ans;
    }
};