class Solution {
public:
    vector<int> findGoodIntegers(int n) {
       long long ans = 0;
       map<int,int> mp;
       for(int i=1;i<=n;i++)
       {
        long long a = pow(i,3);
        if(a >= n)break;
        for(int j=i;j<=n;j++)
        {
            long long a = pow(i,3);
            long long b = pow(j,3);
            if(a >= n or b >= n)break;
            long long sum = a + b;
            if(sum <= n)
            {
                mp[sum]++;
            }else{
                break;
            }
        }
       }
vector<int> ans1;
       for(auto j: mp)
       {
        if(j.second >= 2)
        {
            ans1.push_back(j.first);
        }
       }
       return ans1;
    }
};