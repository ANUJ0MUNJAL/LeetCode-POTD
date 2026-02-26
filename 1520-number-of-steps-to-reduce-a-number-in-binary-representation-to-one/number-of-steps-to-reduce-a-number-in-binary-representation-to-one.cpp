class Solution {
public:
    int numSteps(string s) {
        int count=0;
        while(s.length() != 1){
              if(s[s.length()-1]=='0'){
                 s=s.substr(0,s.length()-1);
              }else{
                  int n=s.length()-1;
                  while(n >=0 and s[n]=='1'){
                       s[n]='0';
                       n--;
                  }
                  if(n >=0 && s[n]=='0'){
                    s[n]='1';
                  }
                  if(n < 0 ){
                    string temp="";
                    temp+='1';
                    temp+=s;
                    s=temp;
                  }
              }
              count++;
        }
        return count;
    }
};