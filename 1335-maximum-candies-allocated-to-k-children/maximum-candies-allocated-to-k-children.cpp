class Solution {
public:
    bool possible(vector<int>&candies,long long value,long long k)
    {
       long long count = 0;

       for(int i=0;i<candies.size();i++)
       {
           count+=(candies[i] / value);

       }
       return count >= k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long start = 1;
        long long end = 1e18;
        long long ans = 0;
        sort(candies.begin(),candies.end());
        while(start <= end)
        {
            long long mid = start + (end - start)/2;
            if(possible(candies,mid,k))
            {
                ans = mid;
                start=mid+1;
            }else{
                end = mid-1;
            }
        }
        return ans;
    }
};