class Solution {
public:
    string removeSubstring(string s, int k) {
        string str;
        int openCount = 0;

        for (char c : s) {
            str.push_back(c);
            if (c == '(') {
                openCount++;
            } else {
                if (str.size() >= 2 * k && openCount >= k) {
                    bool valid = true;
                    int len = str.size();

                    for (int i = len - 2 * k; i < len - k; i++) {
                        if (str[i] != '(') {
                            valid = false;
                            break;
                        }
                    }

                    for (int i = len - k; i < len; i++) {
                        if (str[i] != ')') {
                            valid = false;
                            break;
                        }
                    }

                    if (valid) {
                        str.resize(str.size() - 2 * k);
                        openCount -= k;
                    }
                }
            }
        }

        return str;
    }
};