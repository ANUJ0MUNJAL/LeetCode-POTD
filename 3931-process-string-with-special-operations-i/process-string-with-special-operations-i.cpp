class Solution {
public:
    string processStr(string s) {
        string temp="";
        for(auto j : s)
        {
            if(j=='*')
            {
                if(temp.length()!=0)temp.pop_back();
            }else if(j=='%')
            {
                reverse(temp.begin(),temp.end());
            }else if(j == '#')
            {
                temp+=temp;
            }else{
                temp.push_back(j);
            }
        }
        return temp;
    }
};