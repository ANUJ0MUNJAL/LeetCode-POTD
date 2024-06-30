class Solution {
public:
    vector<int> arr;
    long long dp[301][402];
    int mod=1e9+7;
    long long solve(int n,int index,int inversion){
        if(arr[index] != -1 and inversion != arr[index])return 0;
        if(inversion >= 402) return 0;
        if(index == n-1){
             return 1;
        }
        if(dp[index][inversion]!=-1)return dp[index][inversion];
        long long ans=0;
        for(int inv=0;inv<=index+1; inv++){
         
             ans = (ans %mod+ solve(n,index+1,inversion+index+1 - inv)%mod) % mod;
        }
        return dp[index][inversion]=ans % mod;
    }

    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
             arr.resize(n,-1);
             for(int i=0;i<requirements.size();i++){
                  arr[requirements[i][0]]=requirements[i][1];
             }
             memset(dp,-1,sizeof(dp));
             return solve(n,0,0);
    }
};