class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> temp(rowSum.size(),vector<int>(colSum.size(),0));
        int i=0,j=0;
        while(i < rowSum.size() and j < colSum.size()){
          
             int val = min(rowSum[i],colSum[j]);
             if(val == rowSum[i]){
                 temp[i][j]=rowSum[i];
                 rowSum[i]=INT_MAX;
                 i++;
                 colSum[j]-=val;
             }else{
                temp[i][j]=colSum[j];
                colSum[j]=INT_MAX;
                j++;
                rowSum[i]-=val;
             }
    
        }
        
     return temp;

    }
};