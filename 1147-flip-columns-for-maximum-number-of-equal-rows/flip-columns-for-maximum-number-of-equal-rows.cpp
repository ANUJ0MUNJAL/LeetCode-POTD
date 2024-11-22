class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        map<string,int> mp;
        for(int i=0;i<matrix.size();i++)
        {
            string s="";
            for(int j=0;j<matrix[0].size();j++)
            {
                 if(matrix[i][j] == matrix[i][0])s+='1';
                 else s+='0';
            }
            mp[s]++;
        }
        int ans=1;
        for(auto j: mp)
        {
            ans=max(ans,j.second);
        }
        return ans;
    }
};