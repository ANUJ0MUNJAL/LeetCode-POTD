class Solution {
public:
    string solve(string & temp, int n)
    {
        int value = n - temp.length();

        string ans = "";

        for(int i=0;i<value;i++)
        {
            ans += '0';
        }
        return ans + temp;
    }
    vector<string> generateValidStrings(int n, int k) {
        int mask = 1 << n;

        vector<string> ans;
        
        for(int i=0;i <= mask ;i++)
        {
            int value = i;
            string temp = "";
            while(value)
            {
               temp += to_string(value % 2);
               value /= 2;
            }
            bool flag = true;
            int count = 0;

           
            reverse(temp.begin(),temp.end());

            if(temp.length() > n)break;

            string a = solve(temp,n);

            cout<<a<<endl;

            for(int j=0;j<a.length();j++)
            {
                if(j > 0 and a[j-1] == a[j] and a[j] == '1')flag = false;
                if(a[j] == '1')count += j;
            }
            if(flag and count <=k)
            {
                ans.push_back(a);
            }


        }
        return ans;
    }

};