class Solution {
public:
    int minimumLength(string s) {
        string temp="";
        map<char,int> mp;
        for(auto &j: s){
            mp[j]++;
        }
        int ans=0;
        for(auto &j: mp){
             if(j.second % 2 == 0 and j.second != 0){
                 ans+=2;
             }else{
                if(j.second % 2!=0){
                      ans+=1;
                }
             }
        }
        return ans;
    }
};