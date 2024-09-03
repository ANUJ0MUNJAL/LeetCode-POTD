class Solution {
public:
    int getLucky(string s, int k) {
        string temp="";
        for(int i=0;i<s.length();i++)
        {
            int val = s[i]-'a'+1;
            temp+=to_string(val);
        }
        // cout<<temp<<"\n";
        string val="";
        while(k -- )
        {
            val="";
            int sum=0;
            for(int i=0;i<temp.length();i++)
            {
                sum+=temp[i]-'0';
            }

            val=to_string(sum);
            temp=val;
        }
        return stoi(val);
    }
};