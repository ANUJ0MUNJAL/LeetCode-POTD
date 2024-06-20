class Solution {
public:
    bool possible(int poss,vector<int>&position,int m){
         int count=0;
         int prev;
         for(int i=0;i<position.size();i++){
               if(i == 0){
                    count++;
                    prev=position[i];
                    continue;
               }
               if(abs(prev - position[i]) >= poss){
                    prev=position[i];
                    count++;
               }
         }
         return count >= m;
    }
    int maxDistance(vector<int>& position, int m) {
         sort(position.begin(),position.end());
         int start=1;
         int end=*max_element(position.begin(),position.end());
         int ans=-1;
         while(start <= end){
              int mid=start+(end-start)/2;
              if(possible(mid,position,m)){
                  ans=mid;
                  start=mid+1;
              }else{
                end=mid-1;
              }
         }
         return ans;

    }
};