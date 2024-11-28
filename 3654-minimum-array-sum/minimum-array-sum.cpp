class Solution {
public:
    long long dp[101][101][101];
    int solve(vector<int>&arr,int index,int op1,int op2,int k)
    {
           if(index >= arr.size())return 0;
            if(dp[index][op1][op2]!=-1)return dp[index][op1][op2];
            int first=INT_MAX,second=INT_MAX;
            if(op1 > 0)
             first = (arr[index]+1)/2 + solve(arr,index+1,op1-1,op2,k);
             int val = arr[index];
             int temp = (val + 1)/2;
             if(temp >= k and op2 > 0 and op1 > 0)
             {
                first=min(first,temp - k +solve(arr,index+1,op1-1,op2-1,k));
             }
             if(val >= k and op2 > 0)
             {
                first=min(first,val - k + solve(arr,index+1,op1,op2-1,k));
                if(op1 > 0 and op2 > 0)
                first=min(first,(val - k + 1)/2+solve(arr,index+1,op1-1,op2-1,k));
             }
        
         second = arr[index]+solve(arr,index+1,op1,op2,k);
         return dp[index][op1][op2]=min(first,second);

    }
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,op1,op2,k);
    }
};