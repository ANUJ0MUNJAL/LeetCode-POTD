class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int,int> mp;
        for(int i=0;i<bills.size();i++)
        {
            if(bills[i]==5)
            {
                mp[bills[i]]++;
            }else if(bills[i]==10)
            {
                if(mp[5]==0)
                {
                    return false;
                }else{
                    mp[5]--;
                    mp[10]++;
                }

            }else{
                 if(mp[10]!=0 and mp[5]!=0)
                 {
                   mp[10]--;
                   mp[5]--;
                   mp[20]++;
                 }else{
                    if(mp[5] >= 3)
                    {
                        mp[5]-=3;
                        mp[20]++;
                    }else{
                        return false;
                    }
                 }
            }
        }
        return true;
    }
};