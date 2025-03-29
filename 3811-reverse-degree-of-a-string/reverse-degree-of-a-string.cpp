class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for(int i=0;i<s.length();i++){
            int val = s[i]-'a';
        
            sum+=((26-val)*(i+1));
        }
        return sum;
    }
};