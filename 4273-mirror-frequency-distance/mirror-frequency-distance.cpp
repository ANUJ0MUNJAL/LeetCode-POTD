class Solution {
public:
    int mirrorFrequency(string s) {
        map<char,int> mp;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }
         int ans = 0;
         map<char,int> vis;
        for(auto j: mp)
        {
            if(!vis[j.first] and j.first >= '0' and j.first <='9')
            {
                cout<<j.first<<endl;
                int a = j.second;
                int val = '9' - j.first;
                int b = mp[(char)('0'+val)];
                
                vis[j.first]=1;
                vis[(char)('0'+val)] = 1;
                cout<<a<<" "<<b<<endl;
                ans+=(abs(a-b));
            }else if(!vis[j.first]){
                     cout<<j.first<<endl;
                int a = j.second;
                int val = 'z' - j.first;
                
                int b = mp[(char)'a'+val];
              
                vis[j.first]=1;
                vis[(char)'a'+val] = 1;
                cout<<a<<" "<<b<<endl;
                ans+=(abs(a-b));
            }
        }
        return ans;
    }
};