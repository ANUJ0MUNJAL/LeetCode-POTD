class Solution {
public:
      void computeLPS(string pattern, vector<int>& lps) {
                 int M = pattern.length();
                 int len = 0; // Length of the previous longest prefix & suffix
             
                 lps[0] = 0; // Because there is no proper suffix and prefix of pattern[0..0]
             
                 int i = 1;
                 while (i < M) {
                     if (pattern[i] == pattern[len]) {
                         len++;
                         lps[i] = len;
                         i++;
                     } else {
                         if (len != 0) {
                             len = lps[len - 1];
                         } else {
                             lps[i] = 0;
                             i++;
                         }
                     }
                 }
             }
             
             vector <int> search(string pat, string txt) {
                 int N = txt.length();
                 int M = pat.length();
                 vector<int> result;
             
                 vector<int> lps(M, 0);
                 computeLPS(pat, lps);
             
                 int i = 0; 
                 int j = 0; 
             
                 while (i < N) {
                     if (pat[j] == txt[i]) {
                         i++;
                         j++;
                     }
             
                     if (j == M) {
                         result.push_back(i-j+1); 
                         j = lps[j - 1];
                     } else if (i < N && pat[j] != txt[i]) {
                         if (j != 0) {
                             j = lps[j - 1];
                         } else {
                             i++;
                         }
                     }
                 }
                 
                 return result;
             }
    string shortestPalindrome(string s) {
        string temp=s;
        string arr=s;
        reverse(s.begin(),s.end());
        temp+='%';
        temp+=s;
        
        vector<int> lps(temp.length());
        computeLPS(temp,lps);
        
        string ans=s.substr(0,s.length()-lps[temp.length()-1]);
        reverse(s.begin(),s.end());
        ans+=s;
        return ans;
    }
};