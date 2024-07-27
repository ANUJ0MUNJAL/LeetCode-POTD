class Solution {
public:
    map<int, bool> memo; // Memoization map to store results of subproblems

    bool solve(string &s, int index, set<string> &st) {
        if (index >= s.length()) {
            return true;
        }

        if (memo.find(index) != memo.end()) { // Check if result is already computed
            return memo[index];
        }

        bool ans = false;
        for (int i = index + 1; i <= s.length(); i++) {
            string temp = s.substr(index, i - index);
            if (st.find(temp) != st.end()) {
                if (s.length() == temp.length()) continue;
                ans = solve(s, i, st);
                if (ans) {
                    memo[index] = true; 
                    return true;
                }
            }
        }

        memo[index] = false; 
        return false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        set<string> st;
        for (auto j : words) {
            st.insert(j);
        }

        vector<string> ans;
        for (int i = 0; i < words.size(); i++) {
            memo.clear(); 
            if (solve(words[i], 0, st)) {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};
