class Solution {
public:
    int minimumCost(vector<int>& nums) {
        
            int second=0,third=INT_MAX;
            int val=INT_MAX;
            for(int j=1;j<nums.size()-1;j++){
                second=nums[j];
                third=INT_MAX;
                for(int k=j+1;k<nums.size();k++){
                    cout<<nums[k]<<" ";
                    third=min(third,nums[k]);
                }
                // cout<<second<<" "<<third<<endl;
                val=min(val,nums[0]+second+third);
            }
        return val;
    }
};