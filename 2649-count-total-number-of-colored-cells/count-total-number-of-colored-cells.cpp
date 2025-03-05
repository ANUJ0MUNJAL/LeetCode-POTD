class Solution {
public:
    long long coloredCells(int n) {
       if(n == 1)return 1;
       n--;
      long long sum = 2 * (n);
      sum *= (n+1);
      return sum+1;


    }
};