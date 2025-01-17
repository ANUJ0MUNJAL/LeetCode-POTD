class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int val = 0;
        for(auto j: derived)val ^= j;
        return !val;
    }
};