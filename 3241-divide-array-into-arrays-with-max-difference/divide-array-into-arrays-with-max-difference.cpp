class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=2;i<nums.size();i+=3){
            if(nums[i]-nums[i-2]>k){
                return {};
            }else{
                vector<int> temp;
                temp.push_back(nums[i-2]);
                temp.push_back(nums[i-1]);
                temp.push_back(nums[i]);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};