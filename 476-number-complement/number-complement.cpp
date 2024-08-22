class Solution {
public:
    int findComplement(int num) {
        int ans=0;
        int i=0;
        while(num > 0)
        {
              if(num & 1)
              {

              }else
              {
                   int mask=1<<i;
                   ans=ans|mask;

              }
              num/=2;
              i++;
        }
        return ans;
    }
};