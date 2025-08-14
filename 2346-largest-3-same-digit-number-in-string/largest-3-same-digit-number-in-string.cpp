class Solution {
public:
    string largestGoodInteger(string num) {
        for(int i=9;i>=0;i--){
            int val=i;
            char a='0'+i;
            string ans="";
            ans+=a;
            ans+=a;
            ans+=a;

            if(num.find(ans)!=-1)
                return ans;
        }
        return "";
    }
};