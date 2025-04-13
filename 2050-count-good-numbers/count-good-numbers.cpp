class Solution {
public:
    int mod = 1e9+7;
    long long power(long long base, long long exp){
        if(exp == 0)return 1;
        if(exp == 1)return base;

        long long ans = power(base,exp/2)%mod;
        if(exp % 2 == 0){
            return (ans*ans)%mod;
        }else{
            return (ans*ans*base)%mod;
        }
    }
    int countGoodNumbers(long long n) {
        long long ans = 1;

        long long even = (n+1)/2;

        ans = (ans * power(5*1LL,even))%mod;
        ans = (ans * power(4*1LL,n-even))%mod;
        return ans;

    }
};