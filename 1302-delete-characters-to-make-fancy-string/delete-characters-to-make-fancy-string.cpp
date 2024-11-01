class Solution {
public:
    string makeFancyString(string s) {
        string temp="";
        for(int i=0;i<s.length();i++)
        {
            int count=1;
             while(i+1 < s.length() and s[i] == s[i+1])
             {
                count++;
                i++;
             }

             for(int j=0;j<min(2,count);j++)temp+=s[i];

        }
        return temp;
    }
};