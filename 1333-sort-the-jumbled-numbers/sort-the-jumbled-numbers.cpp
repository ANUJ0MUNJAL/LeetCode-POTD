class Solution {
public:
    static bool cmp(string &a,string &b){
          int first=stoi(a);
          int second=stoi(b);
          if(first==second){
            return first < second;
          }
          return first < second;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        map<int,int> mp;
        map<int,int> mp2;

        for(int i=0;i<mapping.size();i++){
            mp[i]=mapping[i];
            mp2[mapping[i]]=i;
        }
        vector<string> ans;
        for(int i=0;i<nums.size();i++){
             string val=to_string(nums[i]);
        
             string temp="";
             for(int j=0;j<val.length();j++){
                     int t=val[j]-'0';
                     char a = '0'+mp[t];
                     temp+=a;
             }
            
             ans.push_back(temp);
        }
        for(auto &j: ans){
              cout<<j<<" ";
        }
        cout<<"\n";
        sort(ans.begin(),ans.end(),cmp);
        vector<int> v;
        for(int i=0;i<ans.size();i++){
            string temp="";
            for(int j=0;j<ans[i].length();j++){
                  int t=ans[i][j]-'0';
                  char a='0'+mp2[t];
                  temp+=a;
            }
            int val=stoi(temp);
            v.push_back(val);

        }
        return v;

    }
};