class Solution {
public:
    bool possible(vector<int>&ranks,long long value,int cars)
    {
         long long ans = 0;
       
         for(int i=0;i<ranks.size();i++)
         {
             long long val = value / ranks[i];

             ans += sqrt(val);
             if(ans >= cars)return true;
         }
         return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
         long long start = 1;
         long long end = 1e18;
         long long ans = end;
         while(start <= end)
         {
            long long mid = start+(end-start)/2;
          
            if(possible(ranks,mid,cars))
            {
                ans = mid;
                end = mid-1;
            }else{
                start=mid+1;
            }
         }
         return ans;
    }
};