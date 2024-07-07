class Solution {
public:
    string getEncryptedString(string s, int k) {
        string temp=s;
        for(int i=0;i<s.length();i++){
              int val=i;
              val+=k;
               val%=s.length();
               s[i]=temp[val];
        }
        return s;
    }
};