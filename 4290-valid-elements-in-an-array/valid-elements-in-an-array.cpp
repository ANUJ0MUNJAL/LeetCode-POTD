class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        vector<int> ans;
      
        for(int i=0;i<=nums.size()-1;i++)
        {
              int maxi = -1;
              for(int j=0;j<i;j++)
              {
                maxi = max(maxi,nums[j]);
              }
              int maxir = -1;
              for(int j=i+1;j<nums.size();j++)
              {
                maxir = max(maxir,nums[j]);
              }
              if(nums[i] > maxi or nums[i] > maxir)
              {
                ans.push_back(nums[i]);
              }
        }
        return ans;
    }
};