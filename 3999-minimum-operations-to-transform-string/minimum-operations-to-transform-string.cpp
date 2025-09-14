class Solution {
public:
    int minOperations(string s) {
        int mini = INT_MAX;
        for(int i=0;i<s.length();i++)
        {
            if(s[i] > 'a' and s[i] <='z')
            {
                mini = min(mini,s[i]-'a');
            }
        }

        if(mini == INT_MAX)return 0;

        return 26 - mini;
    }
};