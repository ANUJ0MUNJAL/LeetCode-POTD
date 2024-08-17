class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if( k==1)
        return nums;
        int wrong=-1;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
             if(i+1 < nums.size() and ((nums[i] >=  nums[i+1]) or( nums[i]+1 != nums[i+1])))
             {
                 wrong=i;
             }
             if(i+1<nums.size() and i+1 >= k-1)
             {
                  if(wrong < i-k+2)
                  {
                      ans.push_back(nums[i+1]);
                  }else{
                      ans.push_back(-1);
                  }
             }
         
        }
        return ans;
    }
};