class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
         map<char,int> mp;
         for(int i=0;i<chars.length();i++)
          {
            mp[chars[i]]=vals[i];
          }
          vector<int> arr;
          for(int i=0;i<s.length();i++)
          {
              if(mp.count(s[i]))
              {
                arr.push_back(mp[s[i]]);
              }else{
                arr.push_back(s[i]-'a'+1);
              }
          }
          int maxi=0;
          int sum=0;
          for(int i=0;i<arr.size();i++)
          {
                sum+=arr[i];
                if(sum < 0)
                {
                    sum=0;
                }
                maxi=max(maxi,sum);
          }
          return maxi;


    }
};