class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k > s.length())return false;
        map<char,int> mp;
        for(auto j: s)mp[j]++;
        int count=0;
        for(auto j: mp)
        {
            if(j.second & 1)count++;
        }
        if(count > k)return false;
        return true;
    }
};