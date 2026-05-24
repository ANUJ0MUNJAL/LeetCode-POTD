class Solution {
public:
    int passwordStrength(string password) {
        map<char,int> mp;
        int ans = 0;
        for(auto j: password)
        {
            if(mp.count(j))continue;

            if(j >= 'a' and j <='z')
            {
                ans++;
            }else if(j >='A' and j <='Z')
            {
                ans+=2;
            }else if(j >='0' and j <='9')
            {
                ans+=3;
            }else{
                ans+=5;
            }
            mp[j]++;
        }
        return ans;
    }
};