class Solution {
public:
    int minOperations(string s1, string s2) {
        int ans = 0;
        for(int i=0;i<s2.length();i++)
        {
            if(s1[i] != s2[i])
            {
                if(s1[i] == '0')
                {
                    ans++;
                }else{
                    if(i+1 < s1.length() and s1[i+1] == '1')
                    {
                        s1[i+1]='0';
                        ans++;
                    }else if(i-1 >=0 and s1[i-1] == '0'){
                        ans+=2;
                        s1[i] = '0';
                    }else if(i+1 < s1.length() and s1[i+1] == '0')
                    {
                        ans+=2;
                        s1[i]='0';
                    }else if(i-1 >=0 and s1[i-1]=='1')
                    {
                        ans += 2;
                        s1[i]='0';
                    }
                    else{
                        return -1;
                    }
                }
            }
        }
       
        return ans;
    }
};