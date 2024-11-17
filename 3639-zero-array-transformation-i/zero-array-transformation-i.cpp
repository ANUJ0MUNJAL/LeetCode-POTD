class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> arr(nums.size()+2,0);
        for(auto j: queries)
        {
             arr[j[0] - 1 + 1]++;
             arr[j[1] + 1]--;
        }
       
        vector<int> prefix(arr.size(),0);
        for(int i=0;i<arr.size();i++)
        {
             if(i == 0)
             {
                 prefix[i]=arr[i];
             }else{
                prefix[i]=prefix[i-1]+arr[i];
             }
        }
        for(auto j: prefix)cout<<j<<" ";
        cout<<endl;
        for(int i=0;i<nums.size();i++)
        {
             int val = prefix[i];
          
             if(nums[i] > abs(val))return false;
        }
        return true;
    }
};