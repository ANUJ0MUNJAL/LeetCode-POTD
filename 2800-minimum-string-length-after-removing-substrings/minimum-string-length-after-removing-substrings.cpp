class Solution {
public:
    int minLength(string s) {
       stack<char> st;
       for(auto j: s)
       {
        if(!st.empty() and j == 'B' and st.top()=='A')
        {
            st.pop();
        }else if(!st.empty() and j == 'D' and st.top()=='C')
        {
            st.pop();
        }
        else{
            st.push(j);
        }
       }
       return st.size();
    }
};