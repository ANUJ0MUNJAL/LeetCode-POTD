class Solution {
public:
    bool pallindrome(string &s){
        int i=0;
        int j = s.length()-1;
        while(i <= j){
            if(s[i++] != s[j--])return false;
        }
        return true;
    }
    int longestPalindrome(string s, string t) {
        set<string> st;
         int maxi = 1;
        for(int i=0;i<s.length();i++){
            string temp="";
            for(int j=i;j<s.length();j++){
                  temp+=s[j];
                  if(pallindrome(temp))
                  {
                    maxi = max(maxi,(int)temp.length());
                  }
                  st.insert(temp);
            }
        }

        set<string> another;
       
        for(int i=0;i<t.length();i++){
            string temp="";
            for(int j=i;j<t.length();j++){
                temp+=t[j];
                if(pallindrome(temp))
                  {
                    maxi = max(maxi,(int)temp.length());
                  }
                another.insert(temp);
            }
        }
       
        for(auto j: st){
            for(auto i: another){
                string temp = j + i;

                if(pallindrome(temp)){
                    maxi=max(maxi,(int)temp.length());
                }
            }
        }
        return maxi;
    }
};