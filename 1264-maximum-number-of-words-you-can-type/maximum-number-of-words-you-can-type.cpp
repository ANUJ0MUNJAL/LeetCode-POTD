class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<string> arr;
        string temp="";
        for(int i=0;i<text.length();i++)
        {
            if(text[i] == ' ')
            {
               arr.push_back(temp);
               temp="";
            }else{
                temp+=text[i];
            }
        }
        if(temp.length() > 0)arr.push_back(temp);
        set<char> st;
        for(auto j: brokenLetters)
        {
            st.insert(j);
        }
        int count = 0;
        for(auto j: arr)
        {
            bool flag = true;
            for(auto i: j)
            {
                if(st.find(i) != st.end())
                {
                    flag=false;
                    break;
                }
            }
            if(!flag)count++;
        }
        return arr.size()-count;
    }
};