class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
       vector<int> temp;
        
        for(int i=1;i<nums.size();i++){
        if(nums[i]%2==0 and nums[i-1]%2==0){
               temp.push_back(i);
            }
            if(nums[i]%2!=0 and nums[i-1]%2!=0){
                temp.push_back(i);
            }
        }
        
        vector<bool> ans;
        
        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];
            
            int index=upper_bound(temp.begin(),temp.end(),l)-temp.begin();
            
            if(index==temp.size()){
                ans.push_back(true);
            }else{
                if(temp[index] <= r){
                    ans.push_back(false);
                }else{
                    ans.push_back(true);
                }
            }
        }
        return ans;
        
    }
};