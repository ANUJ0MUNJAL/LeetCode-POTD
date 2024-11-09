class Solution {
public:
    bool checkString(string s) {
        bool flag=false;
        for(int i=0;i<s.length();i++)
        {
            if(flag and s[i]=='a')return false;
            if(s[i]=='b')flag=true;
        }
        return true;
    }
};