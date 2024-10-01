class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int,int> mp;
        for(auto j: arr)
        {
            mp[(k-j % k)%k]++;
        }
        for(int i=0;i<=k/2;i++)
        {
            if(i == 0)
            {
                if(mp[i] % 2 != 0)return false;
            }else{
                int val = k - i;
                if(mp[i] != mp[val])return false;
            }
        }
        return true;
    }
};