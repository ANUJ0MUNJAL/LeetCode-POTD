class Solution {
public:
    string val;
    void solve(int k,string temp)
    {
          if(temp.length() >= k)
          {
             val=temp;  
             return;
          }
          string ans="";
          for(int i=0;i<temp.length();i++)
          {
               if(temp[i]=='z')ans+='a';
               else{
                   ans+=(temp[i]+1);
               }
          }
         
          temp+=ans;
          
          solve(k,temp);
    }
    char kthCharacter(int k) {
        solve(k,"a");
        return val[k-1];
    }
};