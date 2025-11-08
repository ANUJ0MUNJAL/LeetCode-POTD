class Solution {
public:
    int minimumOneBitOperations(int n) {
          vector<long long> dp(31);
          dp[0]=1;
          for(int i=1;i<31;i++){
              dp[i]=2*dp[i-1]+1;
          }
          int ans=0;
          int anuj=1;

          for(int i=30;i>=0;i--){
              bool isset=(n&(1<<i));
              if(!isset)
                continue;
              if(anuj)
                ans+=dp[i];
              else
                ans-=dp[i];
             anuj^=1;
          }
          return ans;

    }
};