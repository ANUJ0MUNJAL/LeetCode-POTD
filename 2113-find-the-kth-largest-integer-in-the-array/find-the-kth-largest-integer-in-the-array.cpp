class Solution {
public:
    static bool cmp(string &a, string &b)
    {
        if(a.length() == b.length())return a < b;
        return a.size() < b.size();
    }
    string kthLargestNumber(vector<string>& nums, int k) {
         sort(nums.begin(),nums.end(),cmp);
         return nums[nums.size()-k];
    }
};