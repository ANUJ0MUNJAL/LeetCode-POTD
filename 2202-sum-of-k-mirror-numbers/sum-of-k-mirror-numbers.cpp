class Solution {
public:
    bool pal(string &temp)
    {
        int i=0;
        int j = temp.length()-1;
        while(i <= j)
        {
            if(temp[i++]!=temp[j--])return false;
        }
        return true;
    }
    bool basek(string &temp,int base)
    {
        long long value = stoll(temp);
        string a = "";
        while(value != 0)
        {
            int val  = value % base;
            a+=val+'0';
            value/=base;
        }
        string b = a;
        reverse(a.begin(),a.end());
        if(a == b)return true;
        return false;
    }
    long long kMirror(int k, int n) {
        vector<string> prev = {""};
        vector<char> dig = {'0','1','2','3','4','5','6','7','8','9'};
        long long sum = 0;
        while(n)
        {
            vector<string> curr;
            for(auto j: prev)
            {
                if(n == 0)return sum;
                int len = j.length();
                string a = j.substr(0,len/2+len%2),b=j.substr(len/2+len%2,len);
                for(auto j: dig)
                {
                   if(n == 0)return sum;
                    string c = a + j + b;
                    if(stoll(c) == 0)continue;
                    if(!pal(c))continue;
                    curr.push_back(c);
                    if(basek(c,k))
                    {
                        sum += stoll(c);
                        n--;   
                        if(n == 0)return sum;
                    }
                }
                
            }
            
            prev = curr;
        }
        return sum;
    }
};