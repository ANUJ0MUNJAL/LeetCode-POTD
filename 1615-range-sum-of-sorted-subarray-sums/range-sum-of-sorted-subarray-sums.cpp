class Solution {
public:
    int mod=1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> temp;
        for(int i=0;i<nums.size();i++){
             int sum=0;
             for(int j=i;j<nums.size();j++){
                   sum+=nums[j];
                   temp.push_back(sum);
             }
        }
        sort(temp.begin(),temp.end());
        long long ans=0;
        for(int i=left-1;i<=right-1;i++){
           
                  ans=(ans%mod+temp[i]%mod)%mod;
             
        }
        return ans;
    }
};