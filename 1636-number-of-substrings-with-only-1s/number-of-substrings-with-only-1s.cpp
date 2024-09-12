class Solution {
public:
    int mod=1e9+7;
    int numSub(string s) {
        long long ans=0;
        for(int i=0;i<s.length();i++)
        {
             if(s[i]=='1')
             {
                 long long count=0;
                 while(i < s.length() and s[i]=='1')
                 {
                    count++;
                    i++;
                 }
                 ans=(ans%mod+(count%mod*(count+1)%mod)/2)%mod;
             }
        }
        return ans;
    }
};