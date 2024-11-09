class Solution {
public:
    long long minEnd(int n, int x) {
        long long value=x;
         
     
        
        while(--n){
             value=(value+1)|x;
             
        }
        return value;


    }
};