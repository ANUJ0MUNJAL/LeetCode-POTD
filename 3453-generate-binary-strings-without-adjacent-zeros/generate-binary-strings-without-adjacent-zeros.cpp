class Solution {
public:
    vector<string> ans;
    void solve(int n,string s,bool flag){
        if(s.length()==n){
            ans.push_back(s);
            return;
        }
        
        if(s.length()==0 || flag==1)
             solve(n,s+'0',0);
        solve(n,s+'1',1);
        
    }
    vector<string> validStrings(int n) {

        solve(n,"",0);
        return ans;
    }
};