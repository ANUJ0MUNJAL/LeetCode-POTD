class Solution {
public:
    int maxOperations(string s) {
        int count=0;
        int ans=0;
        for(int i=0;i<s.length();i++){
              if(s[i]=='1'){
                  count++;
              }else{
                  while(i < s.length() and s[i]=='0') i++;
                  i--;
                  ans+=count;
              }
        }
        return ans;
    }
};