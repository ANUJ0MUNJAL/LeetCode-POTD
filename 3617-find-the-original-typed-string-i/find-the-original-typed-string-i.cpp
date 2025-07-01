class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1;
        for(int i=0;i<word.length();i++)
        {
            int count = 1;
            while(i+1 < word.length() and word[i] == word[i+1])
            {
                i++;
                count++;
            }
            ans+=(count-1);
        }
        return ans;
    }
};