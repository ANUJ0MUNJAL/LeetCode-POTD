class Solution {
public:
    string clearDigits(string s) {
        vector<int> visited(s.length(),false);
        for(int i=0;i<s.length();i++){
               if(s[i] >='0' and s[i] <='9'){
                      visited[i]=1;
                      for(int j=i-1;j>=0;j--){
                            if(!visited[j]){
                                visited[j]=1;
                                break;
                            }
                      }
               }
        }
        string ans="";
        for(int i=0;i<s.length();i++){
            if(!visited[i]){
                ans+=s[i];
            }
        }
        return ans;
    }
};