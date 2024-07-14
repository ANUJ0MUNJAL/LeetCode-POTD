class Solution {
public:
    string getSmallestString(string s) {
        for(int i=1;i<s.length();i++){
            if(((s[i] & 1) ==(s[i-1] & 1)) and  s[i] < s[i-1]){
                swap(s[i],s[i-1]);
                return s;
            }
        }
        return s;
    }
};