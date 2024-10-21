class Solution {
public:
    int ans=INT_MIN;
    void solve(string &s,int index,set<string> st)
    {
        if(index >= s.length())
        {
            ans=max(ans,(int)st.size());
            return;
        }

        for(int i=index;i<s.length();i++)
        {
             string temp = s.substr(index,i-index+1);
             if(st.find(temp)!=st.end())continue;
             st.insert(temp);
             solve(s,i+1,st);
             st.erase(temp);
        }
    }
    int maxUniqueSplit(string s) {
        set<string> st;
       solve(s,0,st);
       return ans;
    }
};