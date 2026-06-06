class Solution {
public:
    string getHint(string secret, string guess) {
        int bull =0;
        map<char,int> mp;
        for(int i=0;i<guess.length();i++)
        {
            if(secret[i] == guess[i])
            {
                bull++;
            }else{
               mp[guess[i]]++;
            }
        }
        int cow = 0;
        for(int i=0;i<secret.length();i++)
        {
            if(secret[i] == guess[i])continue;
            if(mp.count(secret[i]))
            {
                cow++;
                mp[secret[i]]--;
                if(mp[secret[i]]==0)
                {
                    mp.erase(secret[i]);
                }
            }
        }
        string ans = to_string(bull);
        ans += 'A';
        ans += to_string(cow);
        ans += 'B';
        return ans;
    }
};