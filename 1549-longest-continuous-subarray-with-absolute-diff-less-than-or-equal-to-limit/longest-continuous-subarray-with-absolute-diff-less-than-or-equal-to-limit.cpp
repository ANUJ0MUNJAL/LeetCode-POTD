class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> st;
        int maxi=1;
        int start=0;
        for(int i=0;i<nums.size();i++){
           st.insert(nums[i]);
           while(start < i and (*st.rbegin()-*st.begin()) > limit){
                st.erase(st.find(nums[start]));
                start++;
           }
           maxi=max(maxi,i-start+1);
        }
        return maxi;
    }
};