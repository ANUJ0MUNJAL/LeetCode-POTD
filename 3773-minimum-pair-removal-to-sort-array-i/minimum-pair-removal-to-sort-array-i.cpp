class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int count=0;
        while(true){
             int i=0;
            while(i+1 < nums.size() and nums[i] <= nums[i+1])i++;
             if(i == nums.size()-1)return count;
             vector<int> temp;
             int mini = INT_MAX;
             int start = -1;
            for(int i=0;i<nums.size()-1;i++){
                int sum = nums[i] + nums[i+1];
                if(sum < mini){
                    mini = sum;
                    start = i;
                }
            }
            for(int i=0;i<nums.size();i++){
                if(start == i){
                    temp.push_back(nums[i] + nums[i+1]);
                    i++;
                }else{
                    temp.push_back(nums[i]);
                }
            }
            nums = temp;
            count++;
            
        }
return -1;
    }
};