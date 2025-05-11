class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<pair<int,int>> arr;
        for(int i=0;i<nums.size();i++){
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(),arr.end());
        int count = 0;
        int mini = arr[0].first;
        set<int> st;
      
        st.insert(nums.size());
        for(int i=0;i<arr.size();i++){
            int val = arr[i].first;
            int mini = -1;
            if(val == 0){
                st.insert(arr[i].second);
                continue;
            }
            while(i < arr.size() and arr[i].first == val){
                 auto itr = st.lower_bound(arr[i].second);
                 if(*itr > mini){
                     count++;
                     mini = *itr;
                 }
                 st.insert(arr[i].second);
                 i++;
            }
            i--;
           
        }
        return count;
    }
};