class Solution {
public:
    long long countPairs(vector<string>& words) {
        map<string,int> mp;
        long long count = 0;

        for(int i=0;i<words.size();i++)
        {
            if(mp.find(words[i]) != mp.end())
            {
                count += mp[words[i]];
            }

            for(int j =0;j<26;j++)
            {
                string temp = "";
                for(auto t: words[i])
                {
                    temp += (((t - 'a') + j )%26 + 'a');
                }
                mp[temp]++;
            }
        }
        return count;
    }
};