class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        vector<int> arr(nums.size());
        for(int i=0;i<nums.size();i++){
              arr[i]=target[i]-nums[i];
        }
        long long ans=0;
        int prev=0;
        for(int i=0;i<arr.size();i++){
              if(prev > 0 and arr[i] > 0){
                  if(arr[i] > prev)
                   ans+=abs(arr[i]-prev);
              }else if(prev < 0 and arr[i] < 0){
                  if(arr[i] < prev)
                    ans+=abs(arr[i]-prev);
              }else{
                ans+=abs(arr[i]);
              }
              prev=arr[i];
        }
        return ans;
    }
};