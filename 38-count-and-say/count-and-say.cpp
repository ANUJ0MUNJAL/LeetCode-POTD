class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
           return "1";
        if(n==2)
           return "11";
        string ans="11";
        for(int i=3;i<=n;i++){
            string t="";
            ans=ans+'@';
            int count=1;
            for(int j=1;j<ans.length();j++){
                if(ans[j]!=ans[j-1]){
                    t=t+to_string(count);
                    t=t+ans[j-1];
                    count=1;
                }
                else{
                    count++;
                }
            }
            
            ans=t;
        }
        return ans;

    }
};