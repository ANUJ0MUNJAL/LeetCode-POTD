class Solution {
public:
    int digitFrequencyScore(int n) {
        map<int,int> mp;
        while(n)
        {
            mp[n%10]++;
            n/=10;
        }
        int sum = 0;
        for(auto j: mp)
        {
            sum += (j.first*j.second);
        }
        return sum;
        
        
    }
};