class Solution {
public:
    string countOfAtoms(string formula) {
        stack<string> st;
        map<string,int> mp;
        for(int i=0;i<formula.size();){
            if(formula[i]==')'){
                i++;
                string val="";
                while(i < formula.length() and formula[i] >='0' and formula[i] <='9'){
                    val+=formula[i];
                    i++;
                }
                int value;
                if(val.length()==0){
                    value=1;
                }else
                 value=stoi(val);
                stack<string> st1;
                while(!st.empty() and st.top() != "("){
                      if(st.top()[0] >='0' and st.top()[0] <='9'){
                          int another=stoi(st.top());
                          another*=value;
                          string v=to_string(another);
                          st1.push(v);
                      }else{
                        st1.push(st.top());
                      }
                      st.pop();
                }
                st.pop();
                while(!st1.empty()){
                    st.push(st1.top());
                    st1.pop();
                }
                
            }else{
                if(formula[i] >='A' and formula[i] <='Z'){
                    string val="";
                    val+=formula[i];
                    i++;
                    while(i < formula.length() and formula[i] >='a' and formula[i] <='z'){
                        val+=formula[i];
                        i++;
                    }
                    st.push(val);
                    val="";
                    while(i < formula.length() and formula[i] >='0' and formula[i] <='9'){
                        val+=formula[i];
                        i++;
                    }
                    if(val.length() == 0){
                         st.push("1");
                    }else{
                        st.push(val);
                    }
                }else if(formula[i] == '('){
                    st.push("(");
                    i++;
                }
            }
        }

        while(!st.empty()){
            if(st.top()[0] >='0' and st.top()[0] <='9'){
                  string val=st.top();
                  st.pop();
                  int value=stoi(val);
                  mp[st.top()]+=value;
            }else{
                st.pop();
            }
        }
        string ans="";
        for(auto &j: mp){
              string a=j.first;
              int b=j.second;
            
              string c=to_string(b);
              ans+=a;
              if(c == "1")continue;
              ans+=c;
        }
        return ans;
       
     
    }
};