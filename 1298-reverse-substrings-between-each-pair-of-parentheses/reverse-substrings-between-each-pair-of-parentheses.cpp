class Solution {
public:
    string reverseParentheses(string s) {
        
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]==')'){
                string ans="";
                while(!st.empty() and st.top() != '('){
                      ans+=st.top();
                      st.pop();
                }
                st.pop();
                for(int j=0;j<ans.length();j++){
                    st.push(ans[j]);
                }
            }else{
                st.push(s[i]);
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};