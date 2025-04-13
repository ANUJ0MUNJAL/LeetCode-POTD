class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
           unordered_set<int> st;
           for(int i=0;i<nums.size();i++){
               for(int j=0;j<nums.size();j++){
                st.insert(nums[i] ^ nums[j]);
               }
           }
         
           unordered_set<int> ans;
           for(auto j: st){
            for(int i=0;i<nums.size();i++){
                 ans.insert(j ^ nums[i]);
            }
           }
           return ans.size();
    }
};