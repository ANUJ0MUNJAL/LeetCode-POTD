class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;
        string temp="";
        for(int i=0;i<target.length();i++)
        {
           
            for(int j=0;j<=target[i]-'a';j++)
            {
                
                char v = 'a'+j;
                if(j == 26)v='a';
                 string val = temp + v;
                 ans.push_back(val);
            }
             temp+=target[i];
            

        }
        return ans;
    }
};