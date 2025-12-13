class Solution {
public:
   vector<int> sieve(int n) {
    
    // creation of boolean array
    vector<bool> prime(n + 1, true);
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            
            // marking as false
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    
    vector<int> res;
    for (int p = 2; p <= n; p++){
        if (prime[p]){ 
            res.push_back(p);
        }
    }
    return res;
}
    bool isPrime(int value)
    {
        if(value == 2)return true;
        for(int i=2;i<=sqrt(value);i++)
        {
            if(value % i == 0)return false;
        }
        return true;
    }
    int largestPrime(int n) {
        vector<int> prime = sieve(n);
        int sum = 0;
        vector<int> temp;
        for(int i=0;i<prime.size();i++)
        {
            sum += prime[i];
            if(sum > n)break;
            if(isPrime(sum))temp.push_back(sum);
        }
        if(temp.size() == 0)return 0;
        return temp[temp.size()-1];
    }
};