class Solution {
public:
    string majorityFrequencyGroup(string s) {
        map<char,int> mp;
        int maxi = 0;
        for(auto j: s)mp[j]++;
        map<int,vector<char>> count;
        for(auto j: mp)
        {
            count[j.second].push_back(j.first);
        }
        string a = "";
        for(auto j: count)
        {
            maxi = max(maxi,(int)j.second.size());
        }
        cout<<maxi<<endl;
        for(auto j: count)
        {
            
            if(j.second.size() == maxi)
            {
                a = "";
                for(auto i: j.second)
                {
                    a+=i;
                }
            }
        }
        return a;

        
    }
};