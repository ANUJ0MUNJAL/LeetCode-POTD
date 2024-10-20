class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for(auto j: expression)
        {
              if(j =='(' or j==',')continue;
              else if(j == '&' or j=='!' or j=='f' or j =='t' or j=='|')
              {
                 st.push(j);
              }else if(j ==')')
              {
                    bool first=false,second=false;
                    while(!st.empty() and st.top()!='!' and st.top()!='&' and st.top()!='|')
                    {
                           if(st.top() == 't')first=true;
                           if(st.top() =='f')second=true;
                           st.pop();
                    }
                    char temp = st.top();
                    st.pop();
                    if(temp =='&')
                    {
                         (second == true) ? st.push('f') : st.push('t');
                    }else if(temp == '|')
                    {
                          (first == true) ? st.push('t') : st.push('f');
                    }else if(temp == '!')
                    {
                           (first == true) ? st.push('f') : st.push('t');
                    }

              }
        }
        return st.top() == 't';
    }
};