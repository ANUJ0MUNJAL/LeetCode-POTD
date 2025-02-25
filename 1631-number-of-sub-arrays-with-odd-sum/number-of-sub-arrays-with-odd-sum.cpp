class Solution {
public:
    int mod = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int count = 0;
         int odd = 0,even=0;
         for(int i=0;i<arr.size();i++)
         {
             if(arr[i] % 2 == 0)
             {
                 even++;
             }else{
                swap(odd,even);
                odd++;
             }
             count = (count % mod + odd % mod)%mod;
         }
         return count;
    }
};