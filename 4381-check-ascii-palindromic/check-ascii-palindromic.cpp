class Solution {
public:
    bool pall(string &s)
    {
        int i=0,j=s.length()-1;
        while(i <= j)
        {
            if(s[i++] != s[j--])return false;
        }
        return true;
    }
    bool isPalindromic(string s) {
        string ans = "";
        for(int i=0;i<s.length();i++)
        {
            int val = s[i];
            string temp = "";
            int t = 8;
            while(t--)
            {
                if(val % 2)
                {
                    temp += '1';
                }else{
                    temp += '0';
                }
                val /= 2;
            }
            ans += temp;
        }
        if(pall(ans))
        return true;
        return false;
    }
};