class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
          int start = bounds[0][0];
          int end = bounds[0][1];
          int count = end - start + 1;

          for(int i=1;i<original.size();i++)
          {
            int diff = original[i]-original[i-1];
            start = max(start+diff,bounds[i][0]);
            end = min(end + diff,bounds[i][1]);
            count = end-start+1;
          }
          return count <= 0 ? 0 : count;
    }
};