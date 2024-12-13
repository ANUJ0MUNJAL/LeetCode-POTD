class Solution {
public:
    int solve(int mask,int val,int k,vector<int>&arr)
    {
        if(mask == ((1 << arr.size())-1))return 0;
        int mini=INT_MAX;
        for(int i=0;i<arr.size();i++)
        {
            if(!(mask & (1 << i)))
            {
                int time = (arr[i]+val-1)/val;
                mini=min(mini,time+solve(mask|(1<<i),val+k,k,arr));
            }
        }
        return mini;
    }
    int findMinimumTime(vector<int>& arr, int K) {
         return solve(0,1,K,arr);
    }
};