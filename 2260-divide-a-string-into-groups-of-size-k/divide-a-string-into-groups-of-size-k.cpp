class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        for(int i=0;i<s.length();)
        {
            string temp="";
            int count = 0;
            while(i < s.length() and count < k)
            {
                 temp+=s[i];
                 i++;
                 count++;
            }
            if(temp.length() == k)ans.push_back(temp);
            else{
                 while(temp.length() != k)
                 {
                    temp.push_back(fill);
                 }
                 ans.push_back(temp);
            }
        }
        return ans;
    }
};