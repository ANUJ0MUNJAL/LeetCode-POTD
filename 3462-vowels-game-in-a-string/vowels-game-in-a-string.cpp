class Solution {
public:
    bool doesAliceWin(string s) {
        int count=0;
        for(int i=0;i<s.length();i++){
             if(s[i] =='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u')count++;
        }
        if(count & 1)return true;
        int i=s.length()-1;
        bool flag=true;
        string temp="";
        while(i >=0 ){
             if(s[i] =='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u'){
                 if(flag){
                      temp+=s[i];
                      flag=false;
                      i--;
                 }else{
                    if(!flag)return true;
                      break;
                 }
             }
            if(!flag)return true;
             temp+=s[i];
             i--;
        }
       
        return false;
    }
};