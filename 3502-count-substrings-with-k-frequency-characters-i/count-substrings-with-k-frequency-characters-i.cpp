class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        map<char,int> mp;
        int slow=0;
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
            while(slow <= i and mp[s[i]] >= k)
            {
                 ans+=(s.length()-i);
                 mp[s[slow]]--;
                 slow++;
                 
            }
        }
        return ans;
    }
};