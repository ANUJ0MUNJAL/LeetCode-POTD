class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<vector<int>> freq(s.length(),vector<int>(26,0));
        for(int i=0;i<s.length();i++)
        {
             freq[i][s[i]-'a']++;
             if(i != 0)
             {
                vector<int> temp=freq[i-1];
                for(int j=0;j<temp.size();j++)
                {
                     freq[i][j]+=temp[j];
                }
             }
        }
        vector<bool> ans;
        for(int i=0;i<queries.size();i++)
        {
             int l = queries[i][0];
             int r = queries[i][1];

             vector<int> temp(26,0);

             for(int j=0;j<26;j++)
             {
                  temp[j]=freq[r][j];
                  if(l-1 >=0)
                  {
                    temp[j]-=freq[l-1][j];
                  }
             }
             int count=0;
             for(auto j: temp)
             {
                 if(j & 1)count++;
             }
             count-=2*queries[i][2];
             if(count <= 1)ans.push_back(true);
             else ans.push_back(false);
        }
        return ans;
    }
};