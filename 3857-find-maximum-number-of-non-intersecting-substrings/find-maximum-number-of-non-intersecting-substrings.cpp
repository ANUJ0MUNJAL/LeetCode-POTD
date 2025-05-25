class Solution {
public:
    int maxSubstrings(string word) {
        map<char,int> mp;
        int ans = 0;
        for(int i=0;i<word.length();i++)
        {
              if(mp.find(word[i]) != mp.end())
              {
                  if(i - mp[word[i]]+1 >= 4)
                  {
                       ans++;
                       mp.clear();
                  }
              }else{
                 mp[word[i]] = i;
              }
        }
        return ans;
    }
};