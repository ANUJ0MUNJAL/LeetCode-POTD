class Solution {
public:
    bool isvowel(char &a)
    {
        if(a == 'a' or a =='e' or a=='i' or a=='o' or a=='u')return true;
        return false;
    }
    string reverseWords(string s) {
        int count = 0;
        int start = -1;
        vector<string> ans;
        string temp = "";
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == ' ')
            {
                if(start == -1){
                   start = count;
                   ans.push_back(temp);
                }
                else{
                    if(count == start)reverse(temp.begin(),temp.end());
                    ans.push_back(temp);
                }
                count = 0;
                temp = "";
            }else{
                temp+=s[i];
                if(isvowel(s[i]))
                {
                    count++;
                }
            }
        }

        if(count == start)
        {
            reverse(temp.begin(),temp.end());
        }
        ans.push_back(temp);

        string a = "";
        for(auto j: ans)
        {
            a+= j;
            a+=' ';
        }
        return a.substr(0,a.length()-1);


    }
};