class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int>ans(grid.size()*grid.size()+1,0);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                ans[grid[i][j]]++;
            }
        }
        int val,an;
        for(int i=0;i<ans.size();i++){
            if(ans[i]==2){
                val=i;
            }
            if(ans[i]==0){
                an=i;
            }
        }
        return {val,an};
    }
};