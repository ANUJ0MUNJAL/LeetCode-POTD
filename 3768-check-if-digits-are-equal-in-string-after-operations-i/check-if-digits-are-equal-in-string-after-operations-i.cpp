class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.length() != 2)
        {
            string temp = "";
            for(int i=1;i<s.length();i++)
                {
                     int a = s[i]-'0';
                     a+=(s[i-1] - '0');
                     temp += to_string(a % 10);
                }
            s = temp;
        }
        return s[0] == s[1];
    }
};