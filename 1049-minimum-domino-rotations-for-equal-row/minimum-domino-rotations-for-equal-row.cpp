class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int mini = INT_MAX;
        for(int i=1;i<=6;i++){
            bool flag=true;
            int count = 0;
            int value = 0;
            for(int j=0;j<tops.size();j++){
                  if(tops[j]==i){
                      continue;
                  }else if(bottoms[j] == i){
                      count++;
                  }else{
                      flag=false;
                      break;
                  }
            }
            if(flag){
            mini = min(mini,count);
            }
            flag=true;
            count = 0;

            for(int j=0;j<bottoms.size();j++){
                  if(bottoms[j]==i){
                      continue;
                  }else if(tops[j] == i){
                      count++;
                  }else{
                      flag=false;
                      break;
                  }
            }

            if(flag)mini=min(mini,count);
            

        }
        return mini == INT_MAX ? -1 : mini;
    }
};