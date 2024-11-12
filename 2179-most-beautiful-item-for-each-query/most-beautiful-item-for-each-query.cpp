class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        vector<int> maxi(items.size(),0);
        int maxim=0;
        for(int i=0;i<items.size();i++){
            maxi[i]=max(items[i][1],maxim);
            maxim=max(maxim,items[i][1]);
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            auto idx=upper_bound(items.begin(),items.end(),vector<int>{queries[i],INT_MAX})-items.begin();
            if(idx==0){
                ans.push_back(0);
                continue;
            }
            idx--;
            ans.push_back(maxi[idx]);
        }
        return ans;
    }
};