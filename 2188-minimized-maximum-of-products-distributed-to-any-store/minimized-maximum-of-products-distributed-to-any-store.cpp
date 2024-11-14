class Solution {
public:
    bool solve(vector<int>&quantities,int value,int n)
    {
         int ans=0;
         for(int i=0;i<quantities.size();i++)
         {
             int count = (quantities[i]+value-1)/value;
             ans+=count;
         }
         return ans <= n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
         int start=1;
         int end = 1e5;
         int ans=-1;
         while(start <= end)
         {
             int mid = start+(end-start)/2;
             if(solve(quantities,mid,n))
             {
                 ans = mid;
                 end=mid-1;
             }else{
                start=mid+1;
             }
         }
         return ans;
    }
};