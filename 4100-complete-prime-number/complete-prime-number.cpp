class Solution {
public:
    bool isPrime(long long value)
    {
        if(value == 1)return false;
        if(value == 2)return true;
        for(int i=2;i<=sqrt(value);i++)
        {
            if(value % i == 0)return false;
        }
        return true;
    }
    bool completePrime(int num) {
        string temp = to_string(num);
        string ans = "";
        for(int i=0;i<temp.length();i++)
        {
            ans += temp[i];
            cout<<ans<<endl;
            if(!isPrime(stol(ans)))return false;
        }
        ans = "";
        for(int i=temp.length()-1;i>=0;i--)
        {
            string val = temp[i] + ans;
            cout<<val<<endl;
            if(!isPrime(stol(val)))return false;

            ans = val;

        }
        return true;
    }
};