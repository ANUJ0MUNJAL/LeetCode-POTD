class Solution {
public:
    
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefix(words.size(),0);
        set<char> st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        for(int i=0;i<words.size();i++)
        {
            if(i == 0)
            {
                 if(st.find(words[i][0])!=st.end() and st.find(words[i][words[i].length()-1])!=st.end())
                 {
                    prefix[i]=1;
                 }
            }else{
                prefix[i]+=prefix[i-1];
                if(st.find(words[i][0])!=st.end() and st.find(words[i][words[i].length()-1])!=st.end())
                 {
                    prefix[i]+=1;
                 }
            }
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++)
        {
            int u = queries[i][0];
            int v = queries[i][1];

            if(u == 0)ans.push_back(prefix[v]);
            else ans.push_back(prefix[v]-prefix[u-1]);
        }
        return ans;
    }
};