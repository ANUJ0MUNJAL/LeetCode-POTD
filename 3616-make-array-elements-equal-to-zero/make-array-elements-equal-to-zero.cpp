class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        if(nums.size() == 1)
        {
            if(nums[0] == 0)return 2;
            else return 0;
        }
        vector<int> left,right;
        for(int i=0;i < nums.size();i++)
        {
             if(i == 0)
             {
                 left.push_back(nums[i]);
             }else{
                 
                 left.push_back(left.back()+nums[i]);
             }
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
             if(i == nums.size()-1)
             {
                right.push_back(nums[i]);
             }else{
                right.push_back(right.back()+nums[i]);
             }
        }
        int flag=0;
    
        reverse(right.begin(),right.end());
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
             if(i == 0)
             {
                 if(nums[i] == 0 and right[i+1] == 1)count++;
                 if(nums[i] == 0 and right[i+1] == 0)count+=2;
             }else if(i == nums.size()-1)
             {
                 if(nums[i] == 0 and  left[i-1] == 1)count++;
                 if(nums[i] == 0 and left[i-1] == 0)count+=2;
             }
             else if(nums[i] == 0 and left[i-1] == right[i+1])
             {
                 count+=2;
             }else if(nums[i] == 0 and ((left[i-1] == right[i+1]+1) or (left[i-1]+1 == right[i+1])))count++;
        }
        return count;
    }
};