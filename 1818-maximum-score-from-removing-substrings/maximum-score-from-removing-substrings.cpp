class Solution {
public:
    int maximumGain(string s, int x, int y) {
          int ans=0;
        stack<int> st;
        int count=0;
    if(x > y){
        for(int i=0;i<s.length();i++){
             while(!st.empty() and s[st.top()]=='a' and s[i]=='b'){
                 st.pop();
                 i++;
                 count++;
             }
             st.push(i);
        }
        ans+=count*x;
    }else{
            for(int i=0;i<s.length();i++){
             while(!st.empty() and s[st.top()]=='b' and s[i]=='a'){
                 st.pop();
                 i++;
                 count++;
             }
             st.push(i);
        }
        ans+=count*y;
    }
      
        string temp="";
        while(!st.empty()){
              temp+=s[st.top()];
              st.pop();
        }
        reverse(temp.begin(),temp.end());
        count=0;
        s=temp;
        if(x < y){
              for(int i=0;i<s.length();i++){
             while(!st.empty() and s[st.top()]=='a' and s[i]=='b'){
                 st.pop();
                 i++;
                 count++;
             }
             st.push(i);
        }
        ans+=count*x;
        }else{

               for(int i=0;i<s.length();i++){
             while(!st.empty() and s[st.top()]=='b' and s[i]=='a'){
                 st.pop();
                 i++;
                 count++;
             }
             st.push(i);
        }
        ans+=count*y;

        }
        return ans;

    }
};