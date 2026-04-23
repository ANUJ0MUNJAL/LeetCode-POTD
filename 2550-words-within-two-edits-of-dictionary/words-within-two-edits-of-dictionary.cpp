class Solution {
public:
    bool solve(string &a,string &b)
    {
        if(a.length() != b.length())return false;
        if(a == b)return true;
        int count = 0;
        for(int i=0;i<a.length();i++)
        {
            if(a[i] != b[i])count++;
        }
        return count <= 2;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;

        for(auto j: queries)
        {
            for(auto i: dictionary)
            {
                if(solve(j,i)){
                  ans.push_back(j);
                  break;
                }
            }
        }
        return ans;
    }
};