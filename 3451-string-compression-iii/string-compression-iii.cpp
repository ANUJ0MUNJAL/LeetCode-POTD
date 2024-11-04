class Solution {
public:
    string compressedString(string word) {
         string ans="";
         int count=1;
        for(int i=0;i<word.length();i++){
            
            while(i+1< word.length() and word[i]==word[i+1]){
                 i++;
                count++;
                if(count == 9){
                    break;
                }
            }
            ans+=to_string(count);
            ans+=word[i];
            count=1;
        }
        return ans;
    }
};