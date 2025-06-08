class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        vector<int> temp = nums;
        bool one = true;
        int val = k;
        for(int i=0;i<temp.size() and k > 0;i++)
        {
            if(temp[i]==-1)
            {
                 if(i+1 >= nums.size())
                 {
                    one = false;
                 }else{
                    temp[i+1]=-1*temp[i+1];
                    temp[i]=1;
                    k--;
                 }
            }
        }
        for(auto j: temp)if(j == -1)one=false;
        if(one)return true;
        bool minus = true;
        for(int i=0;i<nums.size() and val > 0;i++)
        {
            if(nums[i]==1)
            {
                if(i+1 >= nums.size())
                {
                    return false;
                }else{
                    nums[i+1]=-1*nums[i+1];
                    nums[i]=-1;
                    val--;
                }
            }
        }
        for(auto j: nums)if(j == 1)return false;
        return true;

    }
};