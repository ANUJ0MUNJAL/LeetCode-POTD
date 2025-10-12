class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        map<int,int> mp;
        for(auto j: nums)mp[j]++;
        int sum = 0;
        for(auto j: mp)
        {
            if(j.second % k == 0)
            {
                  sum += (j.second*j.first);
            }
        }
        return sum;
    }
};