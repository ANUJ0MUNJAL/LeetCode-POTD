class Solution {
public:
    long long lastInteger(long long n) {
        bool left = 1;
        long long count = 0;
        long long a = 1;
        long long d = 1;
        long long last = 1;
     

        while(n != 1)
        {
            
            if(left)
            {
                a = last;
                d*=2;  
                n = (n + 1) / 2;
                count++;
                left = 0;
                last = a + (n - 1)*d;
            }else{
                a = last;
                d*=-2;
                n = (n+1)/2;
               
                count++;
                left = 1;

                last = a + (n-1)*d;
                d = abs(d);
            }

            
        }

        return a;
    }
};