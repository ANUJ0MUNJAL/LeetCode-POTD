class Solution {
public:
    long long dp[1001][2][2];
    int solve(vector<int>&nums,vector<int>&prefix,int index,int first,int second,bool one,bool two)
    {
        if(one and two)return 0;
        if(index >= nums.size())
        {
             if(one and two)return 0;
             else return -1e7;
        }
        if(dp[index][one][two]!=-1)return dp[index][one][two];
        int include=0,exclude=0,inc=0;
        if(!one and index+first-1 < nums.size())
        {
             if(index == 0)
               inc=prefix[index+first-1]+solve(nums,prefix,index+first,first,second,true,two);
             else
               inc=prefix[index+first-1]-prefix[index-1]+solve(nums,prefix,index+first,first,second,true,two);
        }
        if(!two and index+second-1 < nums.size())
        {
             if(index == 0)
               include=prefix[index+second-1]+solve(nums,prefix,index+second,first,second,one,true);
             else
               include=prefix[index+second-1]-prefix[index-1]+solve(nums,prefix,index+second,first,second,one,true);
        }

        exclude=solve(nums,prefix,index+1,first,second,one,two);
        
        return dp[index][one][two]=max({inc,include,exclude});
        
          
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        vector<int> prefix(nums.size(),0);
        for(int i=0;i<nums.size();i++)
        {
             if(i == 0)prefix[i]=nums[i];
             else prefix[i]=prefix[i-1]+nums[i];
        }
        memset(dp,-1,sizeof(dp));
        return solve(nums,prefix,0,firstLen,secondLen,0,0);
    }
};