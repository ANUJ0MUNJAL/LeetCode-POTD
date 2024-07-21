class Solution {
public:
    int minChanges(int n, int k) {
        int count=0;
        for(int i=0;i<31;i++){
             int val =  (n >> i) &1;
             int another = (k >> i)&1;
             if(val == 0 and another==1)return -1;
             if(val == another)continue;
             count++;
        }
        return count;
    }
};