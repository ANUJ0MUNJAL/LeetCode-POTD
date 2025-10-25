class Solution {
public:
    int totalMoney(int n) {
        int count=0;
        int prev=1;
        while(n!=0){
            int i=prev;
            for(;n!=0 && i<=prev-1+7;i++){
                 count+=i;
                 n--;
            }
            prev++;
        }
        return count;
    }
};