class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        for(int i=0;i<matrix[0].size();i++){
            int maxi=0,index;
              for(int j=0;j<matrix.size();j++){
                    if(maxi < matrix[j][i]){
                          maxi=matrix[j][i];
                          index=j;
                    }
              }
              int val=*min_element(matrix[index].begin(),matrix[index].end());
              if(val == matrix[index][i])ans.push_back(val);
        }
        return ans;
    }
};