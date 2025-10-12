class Solution {
public:
    bool scoreBalance(string s) {
        int sum = 0;
        for(auto j: s)
        {
            sum+=(j-'a' + 1);
        }
        int count = 0;
        for(int i=0;i<s.length();i++)
        {
            count+=(s[i] -'a'+1);
            sum-=(s[i] -'a' + 1);
          
            if(count == sum)return true;
        }
        return false;

    }
};