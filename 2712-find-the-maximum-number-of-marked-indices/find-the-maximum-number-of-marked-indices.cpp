class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int j = nums.size()/2;
        int count=0;
        for(int i=0;i<nums.size()/2;i++)
        {
               while(j < nums.size() and 2*nums[i] > nums[j])j++;
               if(j < nums.size())count+=2;
               j++;
        }
        return count;
        

    }
};