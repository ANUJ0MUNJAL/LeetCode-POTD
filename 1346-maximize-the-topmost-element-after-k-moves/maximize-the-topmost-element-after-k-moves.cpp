class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if(nums.size()==1 and k % 2!=0)return -1;
        int maxi = -1;
        for(int i=0;i<min(k-1,(int)nums.size());i++)
        {
            maxi=max(maxi,nums[i]);
        }
        if(k < nums.size())maxi=max(maxi,nums[k]);
        return maxi;
    }
};