class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> arr;
        for(int i=0;i<position.size();i++){
            arr.push_back({position[i],speed[i]});
        }
        sort(arr.begin(),arr.end());
        vector<float> ans;
        set<pair<float,int>> st;
        for(int i=0;i<arr.size();i++){
             int val=target-arr[i].first;
             ans.push_back(1.0*val/arr[i].second);
             st.insert({ans.back(),i});
        }
        set<int> st1;
        int count=0;
        while(!st.empty()){
            auto itr=st.rbegin();  
            auto temp = st1.upper_bound(itr->second);
            if(temp==st1.end()){
              st1.insert(itr->second);     
              count++;
            }   
            st.erase(st.find({itr->first,itr->second}));
        }
        return count;
        
    }
};