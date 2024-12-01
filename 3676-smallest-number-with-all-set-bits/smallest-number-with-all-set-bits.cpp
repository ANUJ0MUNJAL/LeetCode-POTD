class Solution {
public:
    int smallestNumber(int n) {
         int val = 1;
         int temp = 1;
         while(temp < n)
         {

            val=val*2;
            temp = val - 1;
         }
         return temp;
    }
};