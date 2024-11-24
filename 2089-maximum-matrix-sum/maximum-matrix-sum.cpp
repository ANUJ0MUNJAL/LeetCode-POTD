class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        vector<int> temp;
        long long ans=0;
        int mini = INT_MAX;
        for(int i=0;i<matrix.size();i++)
        {
             for(int j=0;j<matrix[i].size();j++)
             {
                 if(matrix[i][j] < 0)temp.push_back(matrix[i][j]);
                 else {
                    ans+=matrix[i][j];
                 mini=min(mini,matrix[i][j]);
                 }
             }
        }
        sort(temp.begin(),temp.end());
        for(auto j: temp)
        {
             ans+=abs(j);
        }
      
        if(temp.size() & 1)
        {
            ans-=2*min(abs(temp[temp.size()-1]),mini);
        }
        return ans;
    }
};