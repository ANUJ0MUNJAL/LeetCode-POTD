class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<long long> temp;
        long long ans = 1;
        while(ans <= 1e9)
        {
            temp.push_back(ans);
            ans*=2;
        }
        vector<int> dig(10,0);
        while(n != 0)
        {
            dig[n % 10]++;
            n/=10;
        }
        for(auto j: dig)cout<<j<<" ";
        for(int i=0;i<temp.size();i++)
        {
            long long val = temp[i];
            vector<int> dig1(10,0);
            while(val != 0)
            {
                 dig1[val % 10]++;
                 val/=10;
            }
            
            if(dig == dig1)return true;
        }
        return false;
    }
};