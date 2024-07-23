class Solution {
public:
    long long dp[31][2][2];
    int solve(int index,string &ans,bool flag,bool val){
          if(index >= ans.length()) return 1;
          if(dp[index][flag][val]!=-1)return dp[index][flag][val];
          int limit;
          if(val)
           limit=ans[index]-'0';
           else
             limit=1;
          int an=0;
        
          for(int i=0;i<=limit;i++){
           
           bool val1  = (val and i==limit)?1 : 0;
              if(flag and i==1)
                  return an;
               else{
                if(i==1){
                  an+=solve(index+1,ans,1,val1);
                  }
                else{         
                  an+=solve(index+1,ans,0,val1);
                }
               }
          }
          return dp[index][flag][val]=an;
    }
    int findIntegers(int n) {
        string ans="";
        while(n){
           int val=n%2;
           ans+=to_string(val);
          
           n/=2;
        }
        memset(dp,-1,sizeof(dp));
        
        reverse(ans.begin(),ans.end());
        
        return solve(0,ans,0,1);
       

    }
};