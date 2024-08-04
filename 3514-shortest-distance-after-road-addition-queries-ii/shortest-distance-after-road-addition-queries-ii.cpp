class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        set<int> st;
        vector<int> ans;
        for(int i=0;i<n;i++)st.insert(i);
        for(int i=0;i<queries.size();i++){
             int start=queries[i][0];
             int end=queries[i][1];
             
            auto itr=st.upper_bound(start);
            while(*itr < end){
                itr=st.erase(itr);
            }
            ans.push_back(st.size()-1);
        }
       
        return ans;
    }
};