class Solution {
public:
    int maxDistinct(string s) {
        set<char> st;
        for(auto j: s)st.insert(j);
        return st.size();
    }
};