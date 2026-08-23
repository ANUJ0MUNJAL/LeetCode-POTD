class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
         sort(nums.begin(),nums.end());
         vector<vector<int>> ans;
         while(lower <= upper)
         {
            int value = lower_bound(nums.begin(),nums.end(),lower)-nums.begin();

            

            if(value >= nums.size())
            {
                ans.push_back({lower,upper});
                return ans;
            }else{
                if(nums[value] == lower)
                {
                    lower++;
                    continue;
                }
                ans.push_back({lower,min(upper,nums[value]-1)});
                lower = min(upper+1,nums[value]+1);
            }


         }
         return ans;
    }
};