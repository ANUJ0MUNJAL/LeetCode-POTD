class Solution {
public:
 int poss(int x, int y, char op) {
        if(op == '+') return x + y;
        if(op == '-') return x - y;
        if(op == '*') return x * y;
        return 0;
    }
    vector<int> solve(string s){
         vector<int> ans;
         bool flag=true;
         for(int i=0;i<s.length();i++){
            
            if(!isdigit(s[i])){
                flag=0;
                vector<int> left=solve(s.substr(0,i));
                vector<int> right=solve(s.substr(i+1));

                for(auto j: left){
                      for(auto y: right){
                            int val=poss(j,y,s[i]);
                            ans.push_back(val);
                      }
                }
            }
            
         }
         if(flag)ans.push_back((stoi(s)));
         return ans;
    }
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};