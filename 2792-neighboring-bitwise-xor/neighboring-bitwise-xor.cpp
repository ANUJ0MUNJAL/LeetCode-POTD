class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int sum = accumulate(derived.begin(),derived.end(),0);
        if(sum & 1)return false;
        return true;
    }
};