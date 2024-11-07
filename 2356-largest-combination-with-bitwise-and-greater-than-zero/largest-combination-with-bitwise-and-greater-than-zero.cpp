class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxi=0;
        for(int i=0;i<32;i++)
        {
              int mask = 1<<i;
              int count=0;
              for(int j=0;j<candidates.size();j++)
              {
                  if(mask & candidates[j])count++;
              }
              maxi=max(maxi,count);
        }
        return maxi;
    }
};