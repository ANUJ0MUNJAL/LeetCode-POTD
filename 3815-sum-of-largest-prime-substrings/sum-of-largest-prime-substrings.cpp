class Solution {
public:
    set<long long> st;
       bool prime(string &temp)
    {
         long long val = stol(temp);
         if(val < 2)return false;
         for(int i=2;i<=sqrt(val);i++)
         {
            if(val % i == 0)return false;
         }
         return true;
    }
    long long sumOfLargestPrimes(string s) {
        
        for(int i=0;i<s.length();i++)
        {
            string temp="";
            for(int j=i;j<s.length();j++)
            {
                temp+=s[j];
                if(prime(temp))
                {
                    st.insert(-1*stol(temp));
                }
            }
        }

         long long sum = 0;

        for(int i=0;i<3 and st.size() > 0;i++)
        {
             auto el = st.begin();
             
             if(abs(*el))sum+=abs(*el);
             st.erase(st.begin());
        }
        return sum;

        
    }
};