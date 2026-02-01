class Solution {
public:
    int countMonobit(int n) {
         if(n == 0)return 1;
         if(n == 1)return 2;

         int ans = 2;
         int value = 2;
         while(value <= n)
         {
            value *= 2;
            if(value - 1 <= n)ans++;  
         }
         return ans;
    }
};