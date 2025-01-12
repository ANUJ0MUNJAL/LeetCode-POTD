class Solution {
public:
    long long calculateScore(string s) {
        map<char,stack<int>> mp;
        long long ans = 0;
        for(int i=0;i<s.length();i++)
        {
             int val = s[i]-'a';
             int another = 25-val;
             char c = 'a'+another;
            //  cout<<s[i]<<" "<<c<<endl;
             if(mp[c].size() > 0){
                 ans+=(i-mp[c].top());
                 mp[c].pop();
             }else
             mp[s[i]].push(i);
        }
        return ans;

    }
};