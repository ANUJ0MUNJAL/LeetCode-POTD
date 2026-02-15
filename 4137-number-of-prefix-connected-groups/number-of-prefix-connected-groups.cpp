class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        map<string,int> mp;
        int count = 0;
        for(auto j: words)
        {
            string temp = j.substr(0,k);
            cout<<temp<<endl;
            mp[temp]++;
        }
        for(auto j: mp)
        {
            if(j.first.length() != k)continue;
            if(j.second > 1)count++;
        }
        return count;

    }
};