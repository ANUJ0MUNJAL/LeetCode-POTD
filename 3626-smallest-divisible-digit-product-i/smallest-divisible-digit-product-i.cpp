class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true)
        {

            string temp = to_string(n);
            int ans=1;
            for(int i=0;i<temp.length();i++)
            {
                 ans*=(temp[i]-'0');
            }
            if(ans % t == 0)return n;
            n++;
        }
        return -1;

    }
};