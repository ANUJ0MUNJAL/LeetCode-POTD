class Solution {
public:
    string longestNiceSubstring(string s) {
         string ans = "";
         int maxi = 0;
         for(int i=0;i<s.length();i++)
         {
            vector<int> up(26,0);
            vector<int> down(26,0);
            string temp ="";
            for(int j=i;j<s.length();j++)
            {
                   if(s[j] >='a' and s[j] <= 'z')
                   {
                    if(down[s[j] - 'a'] == 0)
                       down[s[j] - 'a']++;
                   }else{
                    if(up[s[j] - 'A'] == 0)
                      up[s[j]- 'A']++;
                  }
                  temp+=s[j];

                  if(up == down and temp.length() > maxi)
                  {
                    maxi = temp.length();
                    ans = temp;
                  }

            }
         }
         return ans;
    }
};