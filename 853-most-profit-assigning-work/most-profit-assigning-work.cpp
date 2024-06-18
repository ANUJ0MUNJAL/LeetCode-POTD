class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> arr;
        for(int i=0;i<difficulty.size();i++){
            arr.push_back({difficulty[i],profit[i]});
        }
        sort(arr.begin(),arr.end());
    
        set<pair<int,int>> st;
        int maxi=0;
        for(int i=0;i<difficulty.size();i++){
            maxi=max(maxi,arr[i].second);
            st.insert({arr[i].first,maxi});
        }
        // for(auto &j: arr){
        //     cout<<j.first<<" "<<j.second<<"\n";
        // }
        int ans=0;
        for(int i=0;i<worker.size();i++){
            
            auto itr=st.upper_bound({worker[i],INT_MAX});
            if(itr==st.begin()){
                 continue;
            }
            itr--;
            ans+=itr->second;
        }
        return ans;
    }
};