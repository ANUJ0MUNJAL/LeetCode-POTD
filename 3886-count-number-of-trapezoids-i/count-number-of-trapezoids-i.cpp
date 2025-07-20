class Solution {
public:
    int mod = 1e9+7;
    int countTrapezoids(vector<vector<int>>& points) {
         map<int,vector<int>> mp;
         for(auto j: points)
         {
            mp[j[1]].push_back(j[0]);
         }
        
         vector<long long> ans;
        
         for(auto j: mp)
         {
            long long val = mp[j.first].size();
            long long value = (val*(val-1))%mod;
            ans.push_back(value / 2);
         }
         vector<long long> prefix(ans.size(),0);
         prefix[ans.size()-1] = ans[ans.size()-1];
         for(int i=ans.size()-2;i>=0;i--)
         {
            prefix[i] = (prefix[i+1] % mod +ans[i] % mod)%mod;
         }
         long long answer = 0;
         for(int i=0;i<prefix.size()-1;i++)
         {
                 answer = (answer%mod +  (1ll * ans[i]%mod * prefix[i+1]%mod)%mod)%mod;
         }
         return answer;
         
    }
};