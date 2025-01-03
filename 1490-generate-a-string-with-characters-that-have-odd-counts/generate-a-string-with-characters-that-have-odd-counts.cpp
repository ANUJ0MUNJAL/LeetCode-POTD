class Solution {
public:
    string generateTheString(int n) {
        string temp = "";
        if(n & 1)
        {
            return string(n,'a');
        }else{
            return 'a'+string(n-1,'b');
        }
    }
};