class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int j = 0;
        for(int i=0;i<str1.length() and j < str2.length();i++)
        {
            if(str1[i] == str2[j])
            {
                j++;
                continue;
            }
            int first = str1[i]-'a';
            if(first == 25)first=0;
            else first++;
            int second =str2[j]-'a';
            if(first == second)j++;
        }
        if(j >= str2.length())return true;
        return false;
    }
};