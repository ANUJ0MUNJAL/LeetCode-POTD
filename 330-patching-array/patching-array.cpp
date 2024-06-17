class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int count=0;
        long long maxi=1;
        int i=0;
        while(maxi <= n){
            if(i < nums.size() and nums[i] <= maxi){
                maxi+=nums[i];
                i++;
            }else{
                maxi+=maxi;
                count++;
            }
        }
        return count;
    }
};