class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.length() & 1)return false;
        int open=0,close=0;
        int count=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')open++;
            else close++;
            if(locked[i]=='0' and s[i]==')')count++; 
            if((close-open)> 2*count)return false;

        }
       
        open=0,close=0,count=0;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]=='(')open++;
            else close++;
            if(locked[i]=='0' and s[i]=='(')count++;
            if((open-close) > 2*count)return false;
        }
        return true;
      
    }
};