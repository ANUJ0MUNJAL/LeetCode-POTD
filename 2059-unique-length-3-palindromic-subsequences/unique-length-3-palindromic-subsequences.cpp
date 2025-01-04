class Solution {
public:
    int countPalindromicSubsequence(string s) {
       vector<pair<int,int>> mp(26,{-1,-1});

       for(int i=0;i<s.length();i++){
           int index=s[i]-'a';
           
           if(mp[index].first==-1){
               mp[index].first=i;
           }
           mp[index].second=i;
           
       }
       int ans=0;
       for(int i=0;i<26;i++){
           if(mp[i].first==-1)
              continue;
            
            int left=mp[i].first;
            int right=mp[i].second;
            
            unordered_set<char>st;
            for(int j=left+1;j<=right-1;j++){
                  st.insert(s[j]);
            }
            ans+=st.size();
       }
       return ans;
    }
};