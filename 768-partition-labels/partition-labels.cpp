class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int> mp;
        for(int i=s.length()-1;i>=0;i--){
               if(mp.find(s[i])==mp.end()){
                    mp[s[i]]=i;
               }
        }
        vector<int> ans;
        int maxi=-1;
        int start=-1;
        for(int i=0;i<s.length();i++){
            
              maxi=max(maxi,mp[s[i]]);
              if(i == maxi){
                  ans.push_back(i-start);
                  start=i;
                  maxi=-1;
                  continue;
              }
           
        }
        return ans;

    }
};