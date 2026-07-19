class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        map<char,int> mp;
        for(auto j: s)mp[j]++;
        string a = "";
        int count = mp[x];
        while(count--)
        {
            a += x;
        }
        count = mp[y];
        while(count--)
        {
            a += y;
        }
        for(auto j: mp)
        {
            if(j.first == x or j.first == y)continue;
            int temp = j.second;
            while(temp--)
            {
                a += j.first;
            }
        }
        reverse(a.begin(),a.end());
        return a;
    }
};