class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        if(s.length() % k != 0)return false;
        k=s.length()/k;
        map<string,int> mp,mp1;
        for(int i=0;i<s.length();i+=k)
        {
            string temp = s.substr(i,k);
            string another = t.substr(i,k);
            
            mp[temp]++;
            mp1[another]++;
        }

        if(mp1 == mp)return true;
        return false;

    }
};