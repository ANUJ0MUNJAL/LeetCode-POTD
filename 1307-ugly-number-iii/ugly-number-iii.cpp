class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long long start=1;
        long long end=2e9;
        long long first=a;
        long long second=b;
        long long third=c;
        long long ab=first*second/__gcd(a,b);
        long long bc=second*third/__gcd(b,c);
        long long ac=third*first/__gcd(a,c);
        long long abc=(first*bc)/__gcd(first,bc);
        cout<<abc<<"\n";
        long long ans=0;
        while(start <= end)
        {
               long long mid = start+(end-start)/2;

               long long total = mid/first+mid/second+mid/third-mid/ab-mid/bc-mid/ac+mid/abc;

               cout<<mid<<" "<<total<<"\n";
               if(total >= n)
               {
                  ans=mid;
                  end=mid-1;
               }else{
                    start=mid+1;
               }

        }
        return ans;
    }
};