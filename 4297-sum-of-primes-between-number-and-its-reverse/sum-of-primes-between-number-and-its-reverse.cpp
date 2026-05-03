class Solution {
public:
   vector<int> sieve(int n) {
    
    vector<bool> prime(n + 1, true);
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            
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
    int sumOfPrimesInRange(int n) {

        vector<int> prime = sieve(1001);
        string temp = to_string(n);
        reverse(temp.begin(),temp.end());

        int rev = stoi(temp);
        int sum = 0;

        for(int i=min(rev,n);i<=max(rev,n);i++)
        {
             auto itr = lower_bound(prime.begin(),prime.end(),i)-prime.begin();
             if(itr != prime.size())
             {
                if(prime[itr] == i)
                {
                    sum += i;
                }
             }
        }
        return sum;
    }
};