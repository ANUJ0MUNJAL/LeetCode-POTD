    #define MAXN 100001
vector<int> spf(MAXN + 1, 1);
class Solution {
public:




// Calculating SPF (Smallest Prime Factor) for every number till MAXN.
void sieve()
{
    // stores smallest prime factor for every number
    spf[0] = 0;
    for (int i = 2; i <= MAXN; i++) {
        if (spf[i] == 1) { 
            
            // if the number is prime ,mark
            // all its multiples who havent
            // gotten their spf yet
            for (int j = i; j <= MAXN; j += i) {
                if (spf[j]== 1) 
                
                    // if its smallest prime factor is
                    // 1 means its spf hasnt been
                    // found yet so change it to i
                    spf[j] = i;
            }
        }
    }
}

vector<vector<int>> getFactorization(vector<int> arr)
{
    sieve();
    vector<vector<int>> ret;
    for(int i = 0; i < arr.size(); i++){
        vector<int> Pfactors;
        int x = arr[i];
        while (x != 1) {
            Pfactors.push_back(spf[x]);
            x = x / spf[x];
        }
        ret.push_back(Pfactors);
    }
    return ret;
}
    int longestSubarray(vector<int>& nums, int k) {
        vector<vector<int>> primefactor = getFactorization(nums);
        int ans = 0;

        map<int,int> mp;

        int slow = 0;
        for(int i=0;i<nums.size();i++)
        {
               for(auto j: primefactor[i])
               {
                   mp[j]++;
               }
            
            if(mp.size() <= k)
            {
                ans = max(ans,i-slow+1);
            }

            while(mp.size() > k)
            {
                for(auto j: primefactor[slow])
                {
                    mp[j]--;
                    if(mp[j] == 0)
                    {
                        mp.erase(j);
                    }
                }
                slow++;
            }
        }
        return ans;
    }
};