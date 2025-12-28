class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        
        for(int i=0;i<matrix.size();i++)
        {
            map<int,int> mp,mp1;
            for(int j=0;j<matrix[0].size();j++)
            {
                mp[matrix[i][j]]++;
                mp1[matrix[j][i]]++;
            }
            if(mp.size() != matrix.size() or mp1.size() != matrix.size())return false;
        }

      
        return true;
    }
};