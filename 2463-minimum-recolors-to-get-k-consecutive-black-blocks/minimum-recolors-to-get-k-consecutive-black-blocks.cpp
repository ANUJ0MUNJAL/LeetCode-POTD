class Solution {
public:
    int minimumRecolors(string blocks, int k) {
         int ans = k;
         int black = 0,white = 0;
         for(int i=0;i<blocks.length();i++)
         {
              if(blocks[i] == 'B')black++;
              else white++;
              if(i >= k-1)
              {
                  ans = min(ans,white);
                  if(blocks[i - k + 1] == 'W')white--;
              }
         }
         return ans;
    }
};