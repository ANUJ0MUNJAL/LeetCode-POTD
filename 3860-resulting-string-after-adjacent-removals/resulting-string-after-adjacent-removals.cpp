class Solution {
public:
    string resultingString(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            if(st.empty())st.push(s[i]);
            else{
        if(abs(st.top() - s[i]) == 1 or (st.top()=='a' and s[i] == 'z') or (st.top() =='z' and s[i]=='a'))
                {
                   st.pop();
                }else{
                    st.push(s[i]);
                }
            }
        }
        string temp="";
        while(!st.empty())
        {
            temp+=st.top();
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};