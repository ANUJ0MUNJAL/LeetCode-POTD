class Solution {
public:
    bool checkGoodInteger(int n) {
        int a =0,b=0;
        while(n)
        {
            int value = n % 10;
            n/=10;
            a += value;
            b += (value*value);
        }
        return (b - a)>=50;
    }
};