class Solution {
public:
    int count = 0;
    void solve(map<int,vector<int>>&mp,int source,int value)
    {
        if(mp[source].size() == 0)
        {
             return;
        }
        count = max(count,value+1);

        for(auto j: mp[source])
        {
             solve(mp,j,value+1);
        }

    }
const unsigned long long int md = 1000000007; 
static const unsigned long long int co = 2000020;
unsigned long long int ft[co];
unsigned long long int fact(unsigned long long int n)
{   
    return ft[n];
}


void fct(){
    ft[0] = 1;
    for(unsigned long long int i = 1; i <= 200000; i++){
        ft[i] = (ft[i-1] * i) % md;
    }
}


unsigned long long int pow(unsigned long long int x, unsigned long long int n, unsigned long long int mod){
    unsigned long long int result = 1; 
    x = x % mod;
    while(n > 0){
        if(n % 2 == 1){
            result = (result * x) % mod;
        }
        n = n >> 1;
        x = (x * x) % mod;   
    }
    return result;
}

unsigned long long int modInverse(unsigned long long int a, unsigned long long int mod) {
    return pow(a, mod - 2, mod);
}

unsigned long long int ncr(unsigned long long int n, unsigned long long int r) {
    if (r > n) return 0;
    unsigned long long int numerator = fact(n);
    unsigned long long int denominator = (fact(r) * fact(n - r)) % md;
    return (numerator * modInverse(denominator, md)) % md;
}
    int assignEdgeWeights(vector<vector<int>>& edges) {
        fct();
       map<int,vector<int>> mp;
       for(auto j: edges){
        mp[j[0]].push_back(j[1]);
       }
       solve(mp,1,0);
       long long ans = 0;
       for(int i=1;i<=count;i+=2)
       {
            ans = (ans%md +  ncr(count,i)%md)%md;
       }

       return ans;
    }
};