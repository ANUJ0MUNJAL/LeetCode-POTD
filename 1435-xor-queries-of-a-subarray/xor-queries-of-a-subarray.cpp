class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
          vector<int> prefix(arr.size());
          prefix[0]=arr[0];
          vector<int> ans;
          for(int i=1;i<arr.size();i++)
          {
            prefix[i]=prefix[i-1]^arr[i];
          }
          for(int i=0;i<queries.size();i++)
          {
            int u= queries[i][0];
            int v = queries[i][1];
            if(u == 0)
            {
                ans.push_back(prefix[v]);
            }else{
                ans.push_back(prefix[v]^prefix[u-1]);
            }
          }
          return ans;
    }
};