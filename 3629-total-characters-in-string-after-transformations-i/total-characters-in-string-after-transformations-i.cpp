class Solution {
public:
    int mod = 1e9+7;
    int lengthAfterTransformations(string s, int t) {
        vector<int> freq(26,0);
        for(auto j: s)freq[j-'a']++;
        while(t--)
        {
             vector<int> temp(26,0);
             for(int i=0;i<26;i++)
             {
                 if(i == 25 and freq[i] > 0){
                     temp[0] = (temp[0]%mod + freq[i]%mod)%mod;
                     temp[1]=(temp[1]%mod+ freq[i]%mod)%mod;
                 }else{
                    if(freq[i] > 0)
                    temp[i+1] = freq[i]%mod;
                 }
             }
             freq = temp;
        }

        int ans = 0;
        for(int i=0;i<freq.size();i++)
        {
              ans = (ans%mod+freq[i]%mod)%mod;
        }

        return ans;

        
    }
};