class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomleft, vector<vector<int>>& topRight) {
        long long ans=0;
        for(int i=0;i<bottomleft.size();i++){
            for(int j=i+1;j<topRight.size();j++){
                int botx = max(bottomleft[i][0],bottomleft[j][0]);
                int boty = max(bottomleft[i][1],bottomleft[j][1]);
                int topx = min(topRight[i][0],topRight[j][0]);
                int topy = min(topRight[i][1],topRight[j][1]);
                
                if(botx > topx || boty > topy){
                    continue;
                }else{
                    long long first=topx-botx;
                    long long second=topy-boty;
                    second = min(first,second);
                    ans=max(ans,second*second);
                }
                
            }
        }
        return ans;
        
    }
};