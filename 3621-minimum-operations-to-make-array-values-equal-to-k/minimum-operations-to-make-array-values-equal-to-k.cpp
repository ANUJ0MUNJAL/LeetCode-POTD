class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        map<int,int> mp;
        for(auto j: nums)mp[j]++;
        int count=0;
        for(auto j: mp)
        {
            if(j.first < k)return -1;
            if(j.first > k)count++;
        }
        return count;
    }
};