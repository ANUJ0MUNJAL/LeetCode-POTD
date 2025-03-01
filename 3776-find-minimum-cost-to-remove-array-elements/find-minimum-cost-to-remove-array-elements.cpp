class Solution {
public:
    long long dp[1001][1001];
    int solve(vector<int>&arr,int index,int prev)
    {
        if(index >= arr.size())
        {
            if(prev < arr.size())
            return arr[prev];
            return 0;
        }
    if(dp[index][prev+1]!=-1)return dp[index][prev+1];
    int first = 1e8,second=1e8,third=1e8;
    if(prev == -1){
        if(index < arr.size())
         first = arr[index];
          if(index+1 < arr.size())
         second = arr[index+1];
          if(index+2 < arr.size())
         third = arr[index+2];

        int a = max(second,third)+solve(arr,index+3,index);
        int b = max(first,third)+solve(arr,index+3,index+1);
        int c = max(first,second)+solve(arr,index+3,index+2);

        return dp[index][prev+1] = min({a,b,c});
    }else if(prev != -1 and index+1 < arr.size()){
          first = arr[prev];
           if(index < arr.size())
          second = arr[index];
           if(index+1 < arr.size())
           third = arr[index+1];

        int a = max(second,third)+solve(arr,index+2,prev);
        int b = max(first,third)+solve(arr,index+2,index);
        int c = max(first,second)+solve(arr,index+2,index+1);

         return dp[index][prev+1] = min({a,b,c});
    }else if(prev != -1 and index+1 >= arr.size())
    {
         first =arr[prev];
         if(index < arr.size())
         second = arr[index];
         else{
            return first;
         }

         return max(first,second);

    }
    return -1;

    }

    int minCost(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        if(nums.size() <= 2)
        {
            return *max_element(nums.begin(),nums.end());
        }

        return solve(nums,0,-1);
    }
};