class Solution {
public:
    
    bool canSortArray(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size()-1;j++){
                if(nums[j]>nums[j+1]){
                    
                    int first=__builtin_popcount(nums[j]);
                    int second=__builtin_popcount(nums[j+1]);
                    if(first!=second)
                        return false;
                    swap(nums[j],nums[j+1]);
                }
            }
        }
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1])
                return false;
            
        }
        return true;
       
    }
};