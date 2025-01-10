class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        map<int,int> freq;
        for(int i=0;i<words2.size();i++)
        {
            map<int,int> temp;
            for(auto j: words2[i])
            {
                 temp[j-'a']++;
            }
            for(auto j: temp)
            {
                 freq[j.first]=max(j.second,freq[j.first]);
            }
        }
        vector<string> ans;
        for(int i=0;i<words1.size();i++)
        {
             map<int,int> mp;
              for(auto j: words1[i])
              {
                  mp[j-'a']++;
              }
             bool flag=false;
              for(auto j: freq)
              {
                  int val=mp[j.first];
                 
                  if(val < j.second)
                  {
                     flag=true;
                     break;
                  }
              }
              if(!flag)ans.push_back(words1[i]);
        }
        return ans;
    }
};