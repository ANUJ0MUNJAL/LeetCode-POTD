class Solution {
public:
    long long dp[1001][1001][4][3];
    int solve(vector<int>&rating,int index,int prev,int k,int flag){
       
        if(index >= rating.size()){
              if(k==0){
                 return 1;
                 }
              return 0;
        }
         if(k==0){
           return 1;
        }
        if(dp[index][prev+1][k][flag+1]!=-1){
            return dp[index][prev+1][k][flag+1];
        }
        int include=0;
     if(prev==-1){
            include=solve(rating,index+1,index,k-1,flag);
        }
      else if(rating[prev] > rating[index] and flag==-1){
              include=solve(rating,index+1,index,k-1,0);
        }
      else if(rating[prev] > rating[index] and flag==0){
              include=solve(rating,index+1,index,k-1,0);
        }
      else if(rating[prev] < rating[index] and flag==-1){
              include=solve(rating,index+1,index,k-1,1);
        }
        else if(rating[prev] < rating[index] and flag==1){
              include=solve(rating,index+1,index,k-1,1);
        }
        int exclude=solve(rating,index+1,prev,k,flag);
        return dp[index][prev+1][k][flag+1]=include+exclude;
    }
    int numTeams(vector<int>& rating) {
        memset(dp,-1,sizeof(dp));
        return solve(rating,0,-1,3,-1);
    }
};