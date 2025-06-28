
class Solution {
public:
    
   
    vector<int> maxSubsequence(vector<int>& nums, int k) {
       
       vector<int> temp = nums;
       vector<int> ans;
       sort(temp.begin(),temp.end());
       multiset<int> st(temp.begin(),temp.begin()+nums.size()-k);
       for(int i =0;i<nums.size();i++)
       {
           if(st.find(nums[i]) != st.end())
           {
               st.erase(st.find(nums[i]));
               continue;
           }else{
            ans.push_back(nums[i]);
           }
       }
       return ans;
        
        
    }
};