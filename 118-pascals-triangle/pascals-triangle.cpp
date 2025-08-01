class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
  
        for(int i=0;i<numRows;i++){
           ans[i].resize(i+1);
           
            for(int j=0;j<ans[i].size();j++){   
                if(j-1<0 || j>=ans[i-1].size())
                   ans[i][j]=1;
                else
                   ans[i][j]=ans[i-1][j]+ans[i-1][j-1];
            }

        }
        return ans;
    }
    
};