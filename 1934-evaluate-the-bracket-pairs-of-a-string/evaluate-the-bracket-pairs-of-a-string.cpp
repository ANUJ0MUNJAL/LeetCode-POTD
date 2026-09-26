class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string,string> mp;
        for(auto j: knowledge)mp[j[0]]=j[1];
        string ans = "";
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == '(')
            {
                i++;
                string temp = "";
                while(i < s.length() and s[i] != ')')
                {
                    temp += s[i];
                    i++;
                }
                if(mp.find(temp)!=mp.end())
                {
                    ans += mp[temp];
                }else{
                    ans += '?';
                }
            }else{
                ans += s[i];
            }
        }
        return ans;
    }
};