class Solution {
public:
    long long dp[11][1 << 10][2];
    int solve(string &a,int index,bool flag,int mask)
    {
        if(index >= a.length())
        {
           return mask!=0;
        }
        if(dp[index][mask][flag]!=-1)return dp[index][mask][flag];
        int start=0,end=9;
         if(flag)
        {
            start=0;
            end=a[index]-'0';
        }
        int ans=0;
        for(int i=start;i<=end;i++)
        {
              if((mask & (1 << i)))continue;
              if(flag)
              {
                  
                int newMask = (mask == 0 && i == 0 ? mask : (mask | (1 << i)));
                  if(i == end)
                  {
                     ans+=solve(a,index+1,flag,newMask);
                  }
                  else
                  {
                  if(i == 0) 
                  {
                    ans+=solve(a,index+1,false,newMask);
                  }else
                  ans+=solve(a,index+1,false,newMask);
                  }
              }else{
                int newMask = (mask == 0 && i == 0 ? mask : (mask | (1 << i)));
                  ans+= solve(a,index+1,flag,newMask);
              }

        }
        return dp[index][mask][flag]=ans;
    }
    int countSpecialNumbers(int n) {
        int mask=0;
        string a = to_string(n);
        memset(dp,-1,sizeof(dp));
        return solve(a,0,1,mask);
    }
};