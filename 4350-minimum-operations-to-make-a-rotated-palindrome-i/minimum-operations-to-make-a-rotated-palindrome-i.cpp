class Solution {
public:
    int minOperations(string s) {
        s = s + s;
        int mini = INT_MAX;

        //abcabc
        //ybyb
        
        for(int i=0;i<s.length()/2;i++)
        {
            int j = i;
            int k = i -1 + s.length()/2;
            int ans = i;

           

            while(j <= k)
            {
                if(s[j] == s[k])
                {
                    j++;
                    k--;
                }else{
                    ans += min(26-abs(s[j]-s[k]),abs(s[j] - s[k]));
                    j++;
                    k--;
                }
            }
            mini = min(mini,ans);

            
        }
        return mini;

    }
};