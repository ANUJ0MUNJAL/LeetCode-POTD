class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
         vector<long long> prefix(grid[0].size(),0);
         vector<long long> pref(grid[0].size(),0);
         for(int i=0;i<grid[0].size();i++)
         {
            if(i == 0)
            {
                prefix[i]=grid[1][i];
                pref[i]=grid[0][i];
            }else{
                prefix[i]+=prefix[i-1];
                prefix[i]+=grid[1][i];
                pref[i]+=pref[i-1];
                pref[i]+=grid[0][i];
            }
         }
         int ans = 0;
         long long val = 0;
         long long value = 1e18;
       
         for(int i=0;i<grid[0].size();i++)
         {
              long long first = pref[pref.size()-1]-pref[i];
              long long second;
              if(i > 0)
              {
                 second = prefix[i-1];
              }
              val = max(first,second);
              value = min(value,val);
         }
         return value;
    }
};