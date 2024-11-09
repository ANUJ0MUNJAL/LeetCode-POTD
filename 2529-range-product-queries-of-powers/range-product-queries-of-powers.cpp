class Solution {
public:
     int mod = 1000000007;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
          vector<int> ans;
          for(int i=0;i<31;i++)
          {
               int mask = 1 << i;
               if(mask & n)
               {
                   ans.push_back(mask);
               }
          }
          vector<int> res;
          for(int i=0;i<queries.size();i++)
          {
               long long val = 1;
               for(int j=queries[i][0];j<=queries[i][1];j++)
               {
                    val=(val * ans[j]) % mod;
               }

               res.push_back(val);
          }
          return res;
    }
};