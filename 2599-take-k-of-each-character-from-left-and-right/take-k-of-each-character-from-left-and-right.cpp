class Solution {
public:
    int takeCharacters(string s, int k) {
        map<char,int> mp;
        for(auto j: s)mp[j]++;
        int slow=0;
        int ans = INT_MIN;
        if(mp['a'] < k or mp['b'] < k or mp['c'] < k)return -1;
        for(int i=0;i < s.length() ;i++)
        {
             mp[s[i]]--;
             while(slow <= i and mp[s[i]] < k)
             {
                mp[s[slow]]++;
                 slow++;
             }
             ans=max(ans,i-slow+1);
        }
        cout<<ans<<"\n";
        return s.length()-ans;
    }
};