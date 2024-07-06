class Solution {
public:
    int passThePillow(int n, int time) {
        int start=1;
        int end=n;
        int flag=1;
        while(n){
            if(time > n-1){
                 time-=n-1;
                 flag=!flag;
            }else{
               if(flag){
                  return time+1;
               }else{
                  return end-time;
               }
            }

        }
        return -1;
    }
};