class Solution {
public:
    vector<string> partitionString(string s) {
        set<string> st;
        string temp="";
        vector<string> ans;
        for(int i=0;i<s.length();i++)
        {
            temp+=s[i];
            if(st.find(temp) == st.end())
            {
                 st.insert(temp);
                 ans.push_back(temp);
                 temp="";
            }
        }
        return ans;
    }
};