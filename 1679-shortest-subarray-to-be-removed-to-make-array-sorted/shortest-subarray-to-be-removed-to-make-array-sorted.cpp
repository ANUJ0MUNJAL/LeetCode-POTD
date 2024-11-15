class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
         int i=0;
         int j = arr.size()-1;
         while(i < j and arr[i] <= arr[i+1])i++;
         if(i == j)return 0;
         while(j >= i and arr[j] >= arr[j-1])j--;

         int ans = min(j,(int)arr.size()-i-1);
         int left=0,right=j;
         while(left <= i and right < arr.size())
         {
              if(arr[left] <= arr[right])
              {
                  left++;
                  ans=min(ans,right-left);
              }else{
                right++;
              }
         }
         return ans;
    }
};