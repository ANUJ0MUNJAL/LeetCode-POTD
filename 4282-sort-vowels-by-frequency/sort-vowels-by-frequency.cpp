class Solution {
public:
    bool vowel(char j)
    {
        return (j == 'a' || j == 'e' || j == 'i' || j == 'o' || j == 'u');
    }

    string sortVowels(string s) {
        map<char,int> temp;
        map<char,int> mp;

        int index = 0;
        for (auto j : s)
        {
            if (vowel(j)) {
                if (!temp.count(j)) {
                    temp[j] = index;
                }
                mp[j]++;
            }
            index++;
        }

        vector<pair<char,int>> arr;
        for (auto j : mp)
        {
            arr.push_back({j.first, j.second});
        }

     
        sort(arr.begin(), arr.end(),
            [&](pair<char,int>& a, pair<char,int>& b) {
                if (a.second != b.second)
                    return a.second > b.second;
                return temp[a.first] < temp[b.first];
            }
        );

        int k = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (vowel(s[i]))
            {
                s[i] = arr[k].first;
                arr[k].second--;
                if (arr[k].second == 0)
                {
                    k++;
                }
            }
        }

        return s;
    }
};