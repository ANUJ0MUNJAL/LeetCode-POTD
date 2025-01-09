class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
        for(auto j: words)
        {
            if(j.find(pref) == 0)
            {
                count++;
            }
        }
        return count;
    }
};