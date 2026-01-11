class Solution {
public:
    int residuePrefixes(string s) {
        map<char,int> mp;
        int count = 0;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
            if((i+1)%3 == mp.size())count++;
        }
        return count;
    }
};